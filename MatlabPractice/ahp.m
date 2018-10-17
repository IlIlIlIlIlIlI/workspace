
%建立名为ahp的函数M文件
function [ weight,CI,RI,CR ] = ahp( A_AHP )

%计算矩阵A_AHP的维度
n = size(A_AHP,1);  

%输入平均随机一致性指标
RI = [0,0,0.52,0.89,1.12,1.26,1.36,1.41,1.46,1.49,1.52,1.54,1.56,1.58,1.59]; 

%计算特征值和特征向量
[V,D] = eig(A_AHP);

%求最大特征值
eigenvalue = diag(D);
lamda_max = max(eigenvalue);
I = find(eigenvalue == lamda_max);

%计算一致比例
CI = (lamda_max - n)/(n-1);
RI = RI(n);
CR = CI/RI;

%判断两两比较判断矩阵的一致性,并计算权重
weight = V(:,1);
if CR<0.1
    disp(['两两比较判断矩阵的一致性的一致性可以接受，CR = ',num2str(CR)])
    disp(['weight = [',num2str(weight),']'])
else
    disp(['两两比较判断矩阵的一致性的一致性不可以接受，CR = ',num2str(CR)])
end

