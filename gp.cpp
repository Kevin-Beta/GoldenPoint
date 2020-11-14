#include <bits/stdc++.h>
using namespace std;

struct {
	float data;
	int grade;
} Player[100];

void game();

int main() {
	freopen("data.txt","r",stdin);
	game();
	return 0;
}

void game() {
	//N人数，a游戏次数
	int  N, a, b, c;

	float co=0.618; //黄金点系数
	int dgrade=1;	//每次得失的分数
	scanf("%d%d", &N, &a);


	for (int i= 0; i < N; i++) {
		Player[i].grade = 0;
	}
	
	bool flag=false;
	
	//游戏开始
	for (int j = 1; j <= a; j++) {
		
		if(flag){
			printf("\n");
		}else{
			flag=true;
		}
		
		float sum=0;
		float G=0,m=0;
		float max=-1,min=101;
		
		//输入每个人的数值，并计算总值
		for (int i = 0; i < N; i++) {
			scanf("%f", &Player[i].data);
			if(Player[i].data>=0&&Player[i].data<=100) {
				sum += Player[i].data;
			}
		}
		
		//计算黄金点
		G = (float)sum*co / N;

		//找出距离黄金点最近和最远的距离
		for (int i = 0; i < N; i++) {
			m = abs((float)Player[i].data - G);
			if (m < min) {
				min = m;
			}
			if (m > max) {
				max = m;
			}
		}
		
		//找出离黄金点最近和最远的输入值，并计算分数得失
		for(int i=0; i<N; i++) {
			float delta=abs((float)Player[i].data - G);
			if(delta == max) {
				Player[i].grade-=dgrade;
			}
			if(delta == min) {
				Player[i].grade+=dgrade;
			}
		}
		
		//输出该轮次后的分数情况
		printf("轮次:%d\n",j);
		printf("黄金点数值为:%f\n",G);
		printf("玩家得分情况:\n");
		for (int i = 0; i < N; i++) {
			printf("玩家%d:%d\n", i+1,Player[i].grade);
		}
	}
	
	//找出得分最高和最低
	int loser[100],winner[100],len_loser=0,len_winner=0;
	int min_grade=101,max_grade=-1;
	
	for (int i = 0; i < N; i++) {
		if (Player[i].grade < min_grade) {
			min_grade = Player[i].grade;
		}
		if (Player[i].grade > max_grade) {
			max_grade = Player[i].grade;
		}
	}
	//printf("%d\n%d\n",min_grade,max_grade);
	
	for(int i = 0 ; i < N; i++) {
		if(Player[i].grade == max_grade) {
			winner[len_winner++]=i+1;  //PS:玩家编号为数组下标+1
		}
		if(Player[i].grade == min_grade) {
			loser[len_loser++]=i+1;
		}
	}
	
	printf("赢家编号是:\n");
	printf("正向得分:");
	for(int i=0;i<len_winner;i++){
		printf("%d%s",winner[i],(i==len_winner-1)?"\n":",");
	}
	printf("反向得分:");
	for(int i=0;i<len_loser;i++){
		printf("%d%s",loser[i],(i==len_loser-1)?"\n":",");
	}
	fclose(stdin);
}
