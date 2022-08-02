#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<pcl/io/pcd_io.h>
#include<pcl/point_types.h>

using namespace std;
int main(int argc, char *argv[])
{
	//定义一种类型表示TXT中xyz
	typedef struct TXT_Point_XYZ
	{
		double x;
		double y;
		double z;
	}TOPOINT_XYZ;

	//读取txt文件
	int num_txt;
	FILE *fp_txt;
	TXT_Point_XYZ txt_points;
	vector<TXT_Point_XYZ> my_vTxtPoints;
	fp_txt = fopen(argv[1],"r");
	 
	if (fp_txt)
	{
		while (fscanf(fp_txt, "%lf %lf %lf", &txt_points.x, &txt_points.y, &txt_points.z) != EOF)
		{//将点存入容器尾部
			my_vTxtPoints.push_back(txt_points);
		}
	}
	else
		cout << "读取txt文件失败"<<fp_txt<<endl;
	 
	num_txt = my_vTxtPoints.size();
	 
	//写入点云数据
	pcl::PointCloud<pcl::PointXYZ> ::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	cloud->width = num_txt;
	cloud->height = 1;
	cloud->is_dense = false;
	cloud->points.resize(cloud->width*cloud->height);
	for (int i = 0; i < cloud->points.size(); ++i)
	{
		cloud->points[i].x = my_vTxtPoints[i].x;
		cloud->points[i].y = my_vTxtPoints[i].y;
		cloud->points[i].z = my_vTxtPoints[i].z;
	}
	pcl::io::savePCDFileASCII(argv[2], *cloud);
	cout<< "从" << argv[1] << "中读取" << cloud->points.size() << "个点写入" << argv[2] << endl;
}