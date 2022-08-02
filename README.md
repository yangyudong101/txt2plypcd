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
  此外发现，当使用pcl命令将pcd转换为ply，但是在mesh中无法使用时，可以使用此代码将pcd转换为txt，再转换为pcd，之后再转换为ply就可以再meshlab中正常显示的。
