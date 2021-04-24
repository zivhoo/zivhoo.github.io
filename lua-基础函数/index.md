# Lua 基础函数


## 模块
- load("" || function [, chunkname , mode , env])
    + 功能： 以字符串为函数体构建一个function(...)代码块编译并返回，如果第一个参数不是字符串而是function，则load会不断的调用function来获得字符串，直至function返回nil。
    + 返回值：function(...)
    + 错误处理：不会引发错误，返回值nil,error
    + 因为需要额外编译（全局环境下）所以比直接定义function要慢。
- loadfile([filename [, mode [, env]]])
    + 功能：从文件加载、编译代码，返回代码块(不调用函数，函数可复用)。
    + 返回值：function(...)
    + 错误处理：不会引发错误，返回值nil,error
- loadstring()
    + 功能：同loadfile,只是从字符串中加载代码。
    + 返回值：function(...)
    + 错误处理：不会引发错误，返回值为nil,error
- dofile(filename)
    + 功能：加载、编译、执行代码块（每次调用都会执行）
    + 返回值：代码块的返回值,`无返回值即nil`
    + 错误处理：引发错误
    ```
    function dofile (filename)
      local f = assert(loadfile(filename))
      return f()
    end
    ```
- require(modname)
    + 功能：搜索目录加载、编译、执行代码块（多次调用只执行一次）  
    + 返回值：代码块的返回值,`无返回值即true`
    + 错误处理：引发错误

## 元表
- getmetatable
    
    
- setmetatable
    
    如果table中存在__metatable字段，函数调用失败。

| 编号  | 元方法    | 符号 |
|:---:| ----- | ---- |
| 1   |__add| +（加） |
| 2   |__sub| -（减） |
| 3   |__mul| *（乘） |
| 4   |__div| /（除） |
| 5   |__mod| %（取余） |
| 6   |__pow| ^ （次方）|
| 7   |__unm| - （取负）|
| 8   |__idiv| // （向下取整除法）|
| 9   |__band| & （按位与）|
| 10  |__bor| \| （按位或）|
| 11  |__bxor| ~ （按位异或）|
| 12  |__bnot| ~ （按位非）|
| 13  |__shl| << （左移）|
| 14  |__shr| >> （右移）|
| 15  |__concat| .. （连接）|
| 16  |__len| # （取长度）|
| 17  |__eq| == （等于）|
| 18  |__lt| < （小于）|
| 19  |__le| <= （小于等于）|
| 20  |__index(tab, key)| 索引 table[key]|
| 21  |__newindex(tab, key, value)| 索引赋值 table[key] = value |
| 22  |__call(selfTab, newTab)| 函数调用操作 func(args) |
| 23  |__tostring(tab)|修改表的输出行为|


## 不触发元方法
- rawequal
- rawlen
- rawget
- rawset

## 类型转换
- tonumber
- tostring

- pcall
- xpcall

## 循环迭代
- next (table [, key])

    返回table中指定key的下一个key和value，key为nil时将返回初始key及其value，传入最后一个key时next会返回nil（可以用来判断表是否为空）。

- pairs

    pairs可以遍历表中全部key，value
- ipairs

    key从数字1开始遍历，每次key累加1，当key对应的value为nil时终止遍历。如果非数字key或1开始key~=1或key数值不连续都不能完全遍历table。

    `
    Note: #和table.getn(t)会在索引中断的地方停止计数，map形式的table不能通过这种方式获得长度
    `

## 其他
- type
- error
- print
- select(number | "#", ...)
- assert(v: any, message: any)
- collectgarbage

## 闭包
lua中两个嵌套函数，内部函数可以访问到外部函数中定义的局部变量（也叫upvalues），其中内部函数和那些被内部函数使用了的外部局部变量叫做闭包。
