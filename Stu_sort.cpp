#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

	//定义学生信息结体 
struct Student{
	char id[15]; 
	int score;
	int location_number;
	int location_rank;		//考场内排名 
}stu[1000];
	
bool cmp(Student a, Student b){
	if(a.score != b.score){
		a.score > b.score; 
	}
	else{
		return strcmp(a.id, b.id);
	}
}
	
int main(){
	//定义n为考场数，k为考场内人数，num为考场内的人数 
	int n, k;
	int num = 0;
	int sum;
	printf("输入考场数："); 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		printf("输入第%d考场人数：",sum);
		scanf("%d",&k);
		for(int j = 0; j < k; j++){
			printf("输入学号和成绩：");
			scanf("%s %d",stu[num].id, &stu[num].score);
			stu[num].location_number = i;
			num++;
		}
		sum ++;
		sort(stu + num - k, stu + num, cmp);  //将该考场学生进行排序 
		stu[num - k].location_rank = 1;
		//对考场其余学生进行排序 
		for(int j = num - k + 1;j < num; j++){
			if(stu[j].score == stu[j - 1].score){
				stu[j].location_rank = stu[j - 1].location_rank;    //考场内排名也相同
			}
			else{
				stu[j].location_rank = j + 1 - (num - k);    //如果分数不相同排名为该考生前人数 
			} 
		}	
	}
	printf("%d\n",num);
	sort(stu, stu + num, cmp);    //将所有考生进行排序
	int r = 1;    //当前考生的排名
	for(int i = 0; i < num; i++){
		if(i > 0 && stu[i].score != stu[i - 1].score){
			r = i + 1;
		}
		printf("%s ",stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].location_rank);
	} 
	return 0;
}
