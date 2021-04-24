# Unity特性


## Editor

+ MenuItem
用于修饰函数，在编辑器中添加菜单项（脚本需要放在Editor目录）
```
[MenuItem(string itemName, bool isValidateFunction, int priority)]
public static void Test(){

}
```

+ CreateAssetMenu

用于创建ScriptObject资源文件菜单（无需放在Editor目录）

+ Header 

+ HideInInspector

+ TextArea

+ CustomEditor

+ OnOpenAsset

+ SerializeField

## 约束
+ RequireComponent(typeof(OneComponent))

+ HideInInspector

## 
+ Conditional


