#BsgToOBJ v0.4
Besiege机械存档转obj模型工具  
by 摸鱼Pro  

本工具使用Visual Studio community 2017，c++10进行开发编译，使用DirectX12函数库进行模型网格转换。工具本身及由工具生成的任何文件仅适用于学习交流，禁止用于商业用途。  
若违反上述条例，造成的任何后果由违反条例的使用者承担。  

使用说明见BsgToOBJ说明文档.pdf  

v0.4.1 2021/1/9  
修正蒙皮厚度只有游戏内一半的问题  
  
v0.4 2021/1/7  
增加基于角度的新蒙皮分辨率步长，可在配置文件中设置，现在会综合边长和边弧度设置步长  
修正.mtl文件d值，现在可在配置文件中设置玻璃的透明度了  

v0.3 2021/1/6  
增加配置文件，现在可以自定点钢的识别长度阈值了  
增加新蒙皮分辨率步长，可在配置文件中设置  
*blender中.mtl文件Kd值未正确与map_Kd叠乘，在启用着色后新蒙皮的纹理贴图会存储为map_Ks，即blender中的高光，与bsg本体渲染效果有较大差异，须手动设置材质混合  
*blender中.mtl文件d值未正确生效，新蒙皮材质为玻璃时须手动启用对应材质的alpha通道  

v0.2 2021/1/5  
增加新蒙皮支持，现在可以转换新蒙皮了  
增加计时功能，现在生成的模型会以"存档名(生成时间)"为文件名  
修正滑铲和侦测块的角度错误  
修正钢筋、皮筋、绞盘长度计算错误  
*当新蒙皮材质为玻璃时，.mtl文件中对应材质的纹理贴图为相对路径，须保证Blocks文件夹与.mtl文件置于同一文件夹下  

v0.1 2020/10/19  
杂项修正  
正式发布  

a0.5 2020/10/18  
增加基于vt,vn计数的防误读机制改进  
修正法向转换错误  
修正UTF8乱码  
编译模式变更为release  

a0.4 2020/10/17  
修正变形钢角度  
修正当存档以本地形式存储皮肤，但本地无该皮肤，工坊有时，皮肤未被读取的bug  

a0.3 2020/10/16  
增加钢筋、皮筋、绞盘读取并转换  
增加.mtl材质库生成  
修正.obj读取策略，现支持3dmax导出的.obj，同时加入防误读机制  
修正零件表参数  
*变形钢角度错误  

a0.2 2020/10/14  
增加基于prefab的零件表构建  
增加大部分零件模型读取并转换  
*部分零件转换错误  

a0.1 2020/10/13  
增加.obj读取并转换  
增加.bsg读取  
增加.obj生成  
