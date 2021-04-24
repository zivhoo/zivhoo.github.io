# Lua与C/C++交互


## C调用Lua

首先读取lua原文件，然后将要调用的lua函数压入栈中，之后再将函数参数依次压入栈中，最后使用函数lua_pcall调用lua函数，另外lua函数返回值会被压入栈中。

### 定义Lua
```
local Test = {}

function Test:waitForCppCall(name, age)
    print(name)
    print(age)
    
    return string.format("Hello I'm %s %d years old.",name,age)
end

return Test
```

### 调用Lua代码
```
    auto L = luaL_newstate();
    luaL_openlibs(L);
    
    // dofile会将代码块中的返回值压入栈
    luaL_dofile(L,"../lua/main.lua");
    // 堆栈情况{table(Test)}

    lua_getfield(L,1,"waitForCppCall");
    // 堆栈情况{table(Test),waitForCppCall()}

    // lua的函数用`：`形式定义的，这里还需要将table传入
    lua_pushvalue(L,1);
    // 堆栈情况{table(Test),waitForCppCall(),table(Test)}

    lua_pushstring(L,"Sean");
    // 堆栈情况{table(Test),waitForCppCall(),table(Test), "Sean"}

    lua_pushnumber(L,20);
    // 堆栈情况{table(Test),waitForCppCall(),table(Test), "Sean", 20}

    lua_pcall(L,3,1,0);
    // 堆栈情况{table(Test),[函数返回值1,函数返回值2,...]}

    lua_close(L);
```

## Lua调用C
### 定义Lua可调用的函数

lua调用的c/c++函数必须满足
```
static int add(lua_State *L){
    int n = lua_gettop(L);
    cout << "参数个数：" << n << endl;
    
    double sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        double d = lua_tonumber(L, i);
        cout << "第" << i << "个参数："  << d << endl;
        sum += d;
    }

    lua_pushnumber(L, sum);
    lua_pushstring(L, "我就测试一下第二返回值。");
    
    return 2;
}
```

### 注册函数到lua解释器中
```
static const struct luaL_Reg reg[] = {
    {"add", add},
    {NULL, NULL},
};

LUALIB_API int luaopen_fun(lua_State *L){
    luaL_newlib(L, reg);
    return 1;
}
```

```
luaL_requiref(L,"ModuleName", luaopen_fun, 1);
```
### 调用C/C++函数
```
print(ModuleName.add(1,2,3,6,5,4))
```

## 类型对应关系
| 数据类型  | C    | Lua |
|:---:| ----- | ---- |
|nil            |无             |  {value=0, tt = t_nil}   |
|boolean        | int  非0, 0   |{value=非0/0， tt = t_boolean}   |
|number         |int/float等    | {value=1.5, tt = t_number}   |
|lightuserdata  |void*, int*, 各种*point | {value=point, tt = t_lightuserdata}   |
|string         |char  str[]   |{value=gco, tt = t_string}   gco=TString obj   |
|table          |无   |{value=gco, tt = t_table}  gco=Table obj   |
|userdata       |无   | {value=gco, tt = t_udata} gco=Udata obj   |
|closure        |无   | {value=gco, tt = t_function} gco=Closure obj   |

## 常用函数
+ lua_gettop(lua_State *L)

    返回栈顶索引（即栈长度）
+ lua_settop (lua_State *L, int idx)
    将栈顶设置为一个指定的位置，即修改栈中元素的数量。如果值比原栈顶高，则高的部分nil补足，如果值比原栈低，则原栈高出的部分舍弃。所以可以用lua_settop(L, 0)来清空栈。
+ lua_close
+ lua_register
+ lua_getglobal(lua_State *L, const char *name)

    把全局变量 name 里的值压栈，然后由Lua去寻找变量name的值，并将变量name的值返回栈顶（替换name）

+ lua_getfield()
+ lua_setfield()

    获取或者设置表中的值

+ lua_pcall(lua_State *L, int nargs, int nresults, int msgh)
    依次将函数参数和函数从栈中弹出，然后调用函数，并把最后函数的返回值压入栈中。

## luaL_*辅助库
    + luaL_newstate
    + luaL_openlibs
    + luaL_dofile

    + lua_push*
    + lua_to*
    + lua_createtable
