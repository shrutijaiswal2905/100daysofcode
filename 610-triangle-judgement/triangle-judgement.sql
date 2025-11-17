# Write your MySQL query statement below
select *, if(x+y>z and y+z>x and x+z>y, "Yes","No") as triangle from triangle

#select x, y, z, case when x+y>z  yz>x and x+z>y then "Yes" else "No" as traandn...