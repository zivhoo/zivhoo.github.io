# Spring Bone


实现现实中柔顺头发的效果

三个主要类：SpringBone、SpringCollider、SpringManager

## SpringBone
用于挂载到所有的骨骼上，最末端骨骼不需要挂载，需要保留原始动画的骨骼也不要挂载。

![SpringBone](/Unity/SpringBone/SpringBone.jpg)

- Child：在骨骼链中，当前骨骼节点的下一个骨骼节点
- Bone Axis： 当人物发生移动时，当前骨骼点摆动的方向。实际测试的时候当我们沿着x轴正向移动人物，Bone Axis为-1时头发会相对人物往x轴负方向移动，为1时会相对人物往x轴正方向移动。因此实际作用的时候应该是人物受力方向和Bone Axis的点积得到最终的受力大小。
- Radius：骨骼的碰撞半径（仅对于spring collider的碰撞
- Is Use Each Bone Force Settings：是否使用自己的Stiffness Force和Drag Force属性，不使用SpringManager中的设置。
- Stiffness Force：硬度，当为0时摆动效果最强，若没有设置阻力会一直摆动。当为1时不会摆动。
- Drag Force：阻尼强度，发生摆动时阻尼越大，摆动后恢复到原来的状态越慢，反之更快。
- Spring Force：在世界坐标系下，作用在Spring Bone上的一个力；可以用来模拟重力或风力
- Threshold：与SpringManager组件的Dynamic Ratio配合使用
- Colliders：与自己发生碰撞的SpringCollider
- Debug


## SpringMnager
用于挂载到GameObject的Root节点上。

![SpringManager](/Unity/SpringBone/SpringManager.jpg)

- Dynamic Ratio：表示飘动的强度，0最小，1最大。
- Stiffness Force：同SpringBone
- Stiffness Curve：同SpringBone
- Drag Force：同SpringBone
- Drag Curve：阻尼强度的变化曲线。
- Spring Bones：需要飘动的骨骼对象，就是挂载了SpringBone的对象。

## SpringCollider

可以阻挡SpringBone穿过的区域
