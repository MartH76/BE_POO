load vs
figure()
plot(vs(:,1), vs(:,2),'r')
hold on
plot(vs(:,1), vs(:,3),'b')
legend('vs')
xlabel('t (s)')
ylabel('ve (V)')
grid()
title('source ve(t)')
