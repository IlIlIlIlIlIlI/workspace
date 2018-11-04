%求y=x^2的定积分
x = 0 : 0.01 : 1;
y = x .^ 2;
plot(x, y);

%Monte Carlo方法
status = 10;
for i = 1 : 4
    point = status .^ i;
    RandData = rand(2, point);
    Below = find(RandData(1, :) .^ 2 > RandData(2, :));
    Outcome(i) = length(Below) / length(RandData);
end
