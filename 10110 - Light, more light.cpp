#include<bits/stdc++.h>
using namespace std;

//�������Ƭ� n ���]�ƭӼơC
	//n ���]�ư��F 1 �M n ���~�A
	//�Y�s�b�䥦�]�� p�A�h�����t�@�]�Ƭ� n / p
	//�Y n ����������ơA�h p = n / p�A�]�ƪ��ƥج��_�ƭ� (�q�O�G��)
	//�_�h�A�]�ƪ��ƥج����ƭ� (�q�O�t��)

int main() {
	int n;
	while(cin >> n && n) {
		int factor = sqrt(n);
		if(factor*factor==n) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
