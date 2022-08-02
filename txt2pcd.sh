# pcd文件转为txt文件
pcl_ply2pcd out.ply out.pcd
./build/pcd2txt in.pcd out.txt

# txt文件转换为pcd文件
./build/txt2pcd in.txt out.pcd
pcl_pcd2ply out.pcd out.ply