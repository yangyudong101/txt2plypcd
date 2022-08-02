# txt2plypcd
需要先安装PCL库，我使用的是PCL1.8

使用方法:

  将文件下git下来之后
  
  mkdir build
  
  cd build
  
  cmake ..
  
  make
  
  cd ..
  
  之后参考.sh文件之中的命令进行格式转换
  
  
  txt转ply可以现将txt转为pcd，然后使用pcl_pcd2ply转换为ply
  
  此外发现，当使用pcl命令将pcd转换为ply，但是在mesh中无法使用（如下图报错）时，可以使用此代码将pcd转换为txt，再转换为pcd，之后再转换为ply就可以再meshlab中正常显示的。
  
 
![20210510191600225](https://user-images.githubusercontent.com/71813713/182336381-91afa289-5e44-4e23-b14c-c855987c3df5.png)
