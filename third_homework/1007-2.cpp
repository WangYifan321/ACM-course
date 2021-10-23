#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int L = -1;
const int R = 1;

struct Node{
    int index;//表示某一个点是中轴左面的还是右面的
    double x;
    double y;
};

Node node[100005],c[100005];
bool cmpx(Node node1,Node node2){
    if(node1.x==node2.x)
    return node1.y<node2.y;
    return node1.x<node2.x;
}

bool cmpy(Node node1,Node node2){
    if(node1.y==node2.y)
    return node1.x<node2.x;
    return node1.y<node2.y;
}

double dis(Node node1,Node node2) {
    double ans=sqrt(pow(node1.x-node2.x,2)+pow(node1.y-node2.y,2));
    return ans;
}

double twomin(double a,double b){
    if(a>b){
        return b;
    }
    return a;
}

double threemin(double a,double b,double c){
    if(a<b && a<c){
        return a;
    }else if(b<a && b<c){
        return b;
    }else return c;
}

//分治法
double divide(int low,int high){
    int x = high-low;
    double res;
    if(x==0){
        return 0;
    }else if(x==1){
        return dis(node[low],node[high]);
    }else if(x==2){
        double a=dis(node[low],node[low+1]);
        double b=dis(node[low],node[high]);
        double c=dis(node[low+1],node[high]);
        return threemin(a,b,c);
    }else{
        double leftmin,rightmin;
        int mid=(low+high)/2;
        int p=0;
        leftmin=divide(low,mid);
        rightmin=divide(mid+1,high);
        res=twomin(leftmin,rightmin);
        int i;
        for(i=mid;i>=low;i--){
            double tmp=node[mid].x-node[i].x;
            if(tmp<res){
                c[p].index=L;
                c[p].x=node[i].x;
                c[p].y=node[i].y;
                p++;
            }else break;
        }
        for(i=mid+1;i<=high;i++){
            double tmp=node[i].x-node[mid].x;
            if(tmp<res){
                c[p].index=R;
                c[p].x=node[i].x;
                c[p].y=node[i].y;
                p++;

            }else break;
        }
        sort(c,c+p,cmpy);
        /*for(int m=0;m<p;m++){
            for(int j=1;(m+j)<p && j<=7;j++){
                if(c[m].index!=c[j+m].index){
                    double tmp=dis(c[m],c[j+m]);
                    if(tmp<res){
                        res=tmp;
                    }
                }
            }
        }*/
        for(int m=0;m<p;m++){
            for(int j=m+1;j<p;j++){
                if(c[j].y-c[m].y<res){
                    res=twomin(dis(c[m],c[j]),res);
                }
                else break;
            }
        }
        return res;
    }
}



int main(){
    int n;
	while (cin >> n)

	{
        if(n==0)
        break;
		double result = 0;
		
		for (int i = 0; i < n; i++)
		{
			node[i].index = 0;
            scanf("%lf %lf",&node[i].x,&node[i].y);
		}
 
		sort(node,node+n,cmpx);
 
		result = divide(0,n-1);
 
		printf("%.2lf\n", result/2);
	}
    return 0;
}