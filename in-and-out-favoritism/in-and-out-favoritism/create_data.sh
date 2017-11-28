#/bin/bash 

make

#Prisioners Game
begin=$(date +%s)
./in-out-fav -g 3 -t d -0.2 1.2 > data/PG-3-d.data
end=$(date +%s)
echo $(expr $end - $begin)

begin=$(date +%s)
./in-out-fav -g 5 -t d -0.2 1.2 > data/PG-5-d.data
end=$(date +%s)
echo $(expr $end - $begin)

begin=$(date +%s)
./in-out-fav -g 10 -t d -0.2 1.2 > data/PG-10-d.data
end=$(date +%s)
echo $(expr $end - $begin)

begin=$(date +%s)
./in-out-fav -g 3 -t g -0.2 1.2 > data/PG-3-g.data
end=$(date +%s)
echo $(expr $end - $begin)

begin=$(date +%s)
./in-out-fav -g 5 -t g -0.2 1.2 > data/PG-5-g.data
end=$(date +%s)
echo $(expr $end - $begin)

begin=$(date +%s)
./in-out-fav -g 10 -t g -0.2 1.2 > data/PG-10-g.data
end=$(date +%s)
echo $(expr $end - $begin)

./in-out-fav -g 3 -t l -0.2 1.2 > data/PG-3-l.data
./in-out-fav -g 5 -t l -0.2 1.2 > data/PG-5-l.data
./in-out-fav -g 10 -t l -0.2 1.2 > data/PG-10-l.data

#Snow-drift Game
./in-out-fav -g 3 -t d -0.5 0.5 > data/SH-3-d.data
./in-out-fav -g 5 -t d -0.5 0.5 > data/SH-5-d.data
./in-out-fav -g 10 -t d -0.5 0.5 > data/SH-10-d.data

./in-out-fav -g 3 -t g -0.5 0.5 > data/SH-3-g.data
./in-out-fav -g 5 -t g -0.5 0.5 > data/SH-5-g.data
./in-out-fav -g 10 -t g -0.5 0.5 > data/SH-10-g.data

./in-out-fav -g 3 -t l -0.5 0.5 > data/SH-3-l.data
./in-out-fav -g 5 -t l -0.5 0.5 > data/SH-5-l.data
./in-out-fav -g 10 -t l -0.5 0.5  > data/SH-10-l.data

#Snow-Drift Game
./in-out-fav  -g 3 -t d 0.5 1.5 > data/SD-3-d.data
./in-out-fav  -g 5 -t d 0.5 1.5 > data/SD-5-d.data
./in-out-fav -g 10 -t d 0.5 1.5 > data/SD-10-d.data

./in-out-fav -g 3 -t g 0.5 1.5 > data/SD-3-g.data
./in-out-fav -g 5 -t g 0.5 1.5 > data/SD-5-g.data
./in-out-fav -g 10 -t g 0.5 1.5 > data/SD-10-g.data

./in-out-fav -g 3 -t l 0.5 1.5 > data/SD-3-l.data
./in-out-fav -g 5 -t l 0.5 1.5 > data/SD-5-l.data
./in-out-fav -g 10 -t l 0.5 1.5 > data/SD-10-l.data
