DAY=$1
echo "🎅🏼 Running solution of day $DAY 🎅🏼\n"
echo "🎄🎄🎄🎄 Part 1"
gcc -o $DAY/day${DAY}_part1.o $DAY/day${DAY}_part1.c && $DAY/day${DAY}_part1.o

echo "\n"
echo "🎄🎄🎄🎄 Part 2"
gcc -o $DAY/day${DAY}_part2.o $DAY/day${DAY}_part2.c && $DAY/day${DAY}_part2.o
echo "\n"