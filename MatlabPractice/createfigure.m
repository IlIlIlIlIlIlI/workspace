function createfigure(cdata1)
%CREATEFIGURE(CDATA1)
%  CDATA1:  image cdata

%  由 MATLAB 于 12-Aug-2018 21:11:03 自动生成

% 创建 figure
figure1 = figure;

% 创建 axes
axes1 = axes('Parent',figure1,...
    'Position',[0.0598051959338127 0.103375529448191 0.879220779220779 0.856962025316456]);
axis off
hold(axes1,'on');

% 创建 image
image(cdata1,'Parent',axes1);

% 取消以下行的注释以保留坐标轴的 X 范围
% xlim(axes1,[0.5 2708.5]);
% 取消以下行的注释以保留坐标轴的 Y 范围
% ylim(axes1,[0.5 1354.5]);
box(axes1,'on');
axis(axes1,'ij');
% 设置其余坐标轴属性
set(axes1,'DataAspectRatio',[1 1 1],'Layer','top','TickDir','out');
