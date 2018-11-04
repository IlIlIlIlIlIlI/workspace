function f2c
f = input('please input the temperature in fahrenheit: ');
while(~isempty(f))
    disp(['==>the tempetarure in degrees celsius is:' num2str((f - 32) * 5/9)])
    f = input('please input the temperature in fahrenheit: ');
end