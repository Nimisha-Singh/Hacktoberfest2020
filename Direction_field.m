% y1' = 4y1 + y2 + y1*y2
% y2' = y1 + 4y2 + y2^2
[a, b] = meshgrid(-6:0.5:5, -6:0.5:1);
da = 4*a + b + a.*b;
db = a + 4*b + b.^2;
dau = da./(sqrt(da.^2 + db.^2));
dbu = db./(sqrt(da.^2 + db.^2));
quiver(a, b, dau, dbu, 0.2, 'r')
hold on
[X, Y] = meshgrid(-6:5, -6:1);
streamline(a, b, da, db, X, Y);
hold off