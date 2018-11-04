function createfigure(cdata1)
%CREATEFIGURE(CDATA1)
%  CDATA1:  image cdata

%  �� MATLAB �� 12-Aug-2018 21:11:03 �Զ�����

% ���� figure
figure1 = figure;

% ���� axes
axes1 = axes('Parent',figure1,...
    'Position',[0.0598051959338127 0.103375529448191 0.879220779220779 0.856962025316456]);
axis off
hold(axes1,'on');

% ���� image
image(cdata1,'Parent',axes1);

% ȡ�������е�ע���Ա���������� X ��Χ
% xlim(axes1,[0.5 2708.5]);
% ȡ�������е�ע���Ա���������� Y ��Χ
% ylim(axes1,[0.5 1354.5]);
box(axes1,'on');
axis(axes1,'ij');
% ������������������
set(axes1,'DataAspectRatio',[1 1 1],'Layer','top','TickDir','out');
