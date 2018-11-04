
%������Ϊahp�ĺ���M�ļ�
function [ weight,CI,RI,CR ] = ahp( A_AHP )

%�������A_AHP��ά��
n = size(A_AHP,1);  

%����ƽ�����һ����ָ��
RI = [0,0,0.52,0.89,1.12,1.26,1.36,1.41,1.46,1.49,1.52,1.54,1.56,1.58,1.59]; 

%��������ֵ����������
[V,D] = eig(A_AHP);

%���������ֵ
eigenvalue = diag(D);
lamda_max = max(eigenvalue);
I = find(eigenvalue == lamda_max);

%����һ�±���
CI = (lamda_max - n)/(n-1);
RI = RI(n);
CR = CI/RI;

%�ж������Ƚ��жϾ����һ����,������Ȩ��
weight = V(:,1);
if CR<0.1
    disp(['�����Ƚ��жϾ����һ���Ե�һ���Կ��Խ��ܣ�CR = ',num2str(CR)])
    disp(['weight = [',num2str(weight),']'])
else
    disp(['�����Ƚ��жϾ����һ���Ե�һ���Բ����Խ��ܣ�CR = ',num2str(CR)])
end

