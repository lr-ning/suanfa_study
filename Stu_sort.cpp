#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

	//����ѧ����Ϣ���� 
struct Student{
	char id[15]; 
	int score;
	int location_number;
	int location_rank;		//���������� 
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
	//����nΪ��������kΪ������������numΪ�����ڵ����� 
	int n, k;
	int num = 0;
	int sum;
	printf("���뿼������"); 
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		printf("�����%d����������",sum);
		scanf("%d",&k);
		for(int j = 0; j < k; j++){
			printf("����ѧ�źͳɼ���");
			scanf("%s %d",stu[num].id, &stu[num].score);
			stu[num].location_number = i;
			num++;
		}
		sum ++;
		sort(stu + num - k, stu + num, cmp);  //���ÿ���ѧ���������� 
		stu[num - k].location_rank = 1;
		//�Կ�������ѧ���������� 
		for(int j = num - k + 1;j < num; j++){
			if(stu[j].score == stu[j - 1].score){
				stu[j].location_rank = stu[j - 1].location_rank;    //����������Ҳ��ͬ
			}
			else{
				stu[j].location_rank = j + 1 - (num - k);    //�����������ͬ����Ϊ�ÿ���ǰ���� 
			} 
		}	
	}
	printf("%d\n",num);
	sort(stu, stu + num, cmp);    //�����п�����������
	int r = 1;    //��ǰ����������
	for(int i = 0; i < num; i++){
		if(i > 0 && stu[i].score != stu[i - 1].score){
			r = i + 1;
		}
		printf("%s ",stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].location_rank);
	} 
	return 0;
}
