# Spring Bone


实现现实中柔顺头发的效果

三个主要类：SpringBone、SpringCollider、SpringManager

## SpringBone
用于挂载到所有的骨骼上，最末端骨骼不需要挂载，需要保留原始动画的骨骼也不要挂载。

![SpringBone](/Unity/SpringBone/SpringBone.jpg)

- Child：下一个骨骼节点
- Bone Axis：骨骼方向
- Radius：骨骼的碰撞半径（仅对于spring collider的碰撞
- Is Use Each Bone Force Settings：是否使用“弹簧骨骼”自己的Stiffness Force和Drag Force属性，而不是用SpringManager的设置。
- Stiffness Force：弹簧回弹力
- Drag Force：阻尼力
- Spring Force：在世界坐标系下，作用在Spring Bone上的一个力；可以用来模拟重力或风力
- Threshold：与SpringManager组件的Dynamic Ratio配合使用
- Colliders：与自己发生碰撞的SpringCollider
- Debug


## SpringMnager
用于挂载到GameObject的Root节点上。

![SpringManager](/Unity/SpringBone/SpringManager.jpg)

- Dynamic Ratio：这个需要配合Spring Bone的Threshold来使用，对于每一个Spring Bone来说，当Threshold小于Dynamic Ratio时，Spring Bone才更新，否则是不更新的。
- Stiffness Force：弹簧回弹力
- Stiffness Curve：弹簧回弹力曲线
- Drag Force：阻尼力
- Drag Curve：阻尼力曲线
- Spring Bones

## SpringCollider

可以阻挡SpringBone穿过的区域
