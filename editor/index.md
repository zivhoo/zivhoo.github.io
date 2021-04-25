# 扩展编辑器


# 扩展编辑器

## 编辑器向导ScriptableWizard

可以在类中定义些成员变量用来接受输入参数。

- helpString
- errorString
- isValid
---
- OnDrawGizmos
- OnWizardCreate()  
- OnWizardOtherButton()
- OnWizardUpdate() 打开向导或内容被修改将调用此函数。
---
- DisplayWizard

  
## 自定义编辑器窗口
+ 继承自EditorWindow
+ 类文件必须放置在Editor文件夹下
+ 重写OnGUI方法
+ 使用EditorWindow.GetWindow<T>("Title");创建窗口

## 自定义特性或Serializable编辑器
+ 继承自PropertyDrawer
+ 类上添加CustomPropertyDrawer特性
+ 重写OnGUI(Rect position, SerializedProperty property, GUIContent label)方法

`出于性能原因，EditorGUILayout函数不能使用与此。`

## MonoBehaviour编辑器
+ 编辑器类名为MonoBehaviour同名+Editor
+ 继承自Editor
+ 类上添加CustomEditor特性
+ 重写OnInspectorGUI或者OnSceneGUI方法

## 四大GUI系统
+ UnityEngine.GUI
+ UnityEngine.GUILayout
+ UnityEditor.EditorGUI
+ UnityEditor.EditorGUILayout

## 其他

### Selection

### EditorUtility
DisplayProgressBar
ClearProgressBar

### Undo

### EditorSceneManager

### EditorApplication

### EditorGUILayout
BeginVertical
EndVertical

BeginHorizontal
EndHorizontal

Space()

LabelField
IntField
FloatField
TextField
Vector2Field
Vector3Field
Vector4Field
ObjectField

TextArea

Slider
ProgressBar

HelpBox

### GUILayout
Label
Button

### GUILayoutUtility
GetRect

### FileUtil
提供了一些文件拷贝，移动位置等操作

### Help
它提供了打开网页地址的功能。

### ObjectPreview
这个类提供了你当前选择的对象数据。 比如，在上面显示攻击和侦测范围的例子中，如果我们只是想让选中的单位才显示预览，那我们可以通过这个类的target来判定。

### Tools
这个类提供了对象批量查找功能，比如，如果我们的工具，想对某一类对象进行打包。 那我们直接使用FindObjectsOfType，拿到所有的对象即可。 TOOL还提供了实例化对象的功能。


### AssetDatabase


### 特性MenuItem

可以向Unity菜单栏或者Inspector添加菜单项。

1. 方法规则

   1. 主方法必须是`static`
   2. 验证方法除了返回值`bool`、方法名必须Validate+主方法名，特性第二个参数为true外，其他与主方法一致。（可选项）
2. 快捷键及特殊按键

    | 字符 | 描述          | 示例                   |
    |------|---------------|------------------------|
    | %    | Ctrl或Command | MenuItem("xxx/xxx %m") |
    | #    | Shift         | MenuItem("xxx/xxx #m") |
    | &    | Alt           | MenuItem("xxx/xxx &m") |
    | _    | 单按键        | MenuItem("xxx/xxx _m") |

    LEFT、RIGHT、UP、DOWN、F1~F12、HOME、END、PGUP 和 PGDN
3. 特殊菜单路径
   
   - GameObject/xxx
   - Assets/xxx
   - CONTEXT/ComponentClass/xxx,可将Component当做参数传递到方法中
   
示例：
```
// 菜单项及校验
[MenuItem("Custom/Menu0")]
static void Menu0(){}
[MenuItem("Custom/Menu0", true)]
static bool ValidateMenu0()
{
    return 1 == 1;
}

// 设置快捷键 Ctrl或Command + Shift + m
[MenuItem("Custom/Menu1 %#m")]
static void Menu1(){}

// 给Transform组件添加Menu2菜单，并将Transform传递过来
[MenuItem("CONTEXT/Transform/Menu2")]
static void Menu2(MenuCommand cmd)
{
    Transform trans = cmd.context as Transform;

    GameObject go = new GameObject("Custom Game Object");
    GameObjectUtility.SetParentAndAlign(go, trans.gameObject);
    Undo.RegisterCreatedObjectUndo(go, "Create " + go.name);
    Selection.activeObject = go;
}
```

### ContextMenuItem

### ContextMenu
