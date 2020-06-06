# Union Find

#### 加权quick-union森林中任意节点的深度为lgN
- 设存在大小为i、j的树, i < j, 且i+j=N
- 假设i的深度最大为lgi
- 将i与j合并时，i的节点深度增加1
- 1+lgi=lg(i+i)<=lg(i+j)=lgk


#### 存在N个触点时成本的增长量级
|算法|构造函数|union()|find()|
|:----:|:----:|:----:|:----:|
|quick-find|N|N|1|
|quick-union|N|树的高度|树的高度|
|加权quick-union|N|lgN|lgN|