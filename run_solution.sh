DAY=$1
echo "🎅🏼 Running solution of day $DAY 🎅🏼\n"
NUM_PARTS=$(ls $DAY | grep -c -E "[0-9]+part[0-9]+\.c")

for PART in $(seq 1 $NUM_PARTS);
do
    echo "🎄🎄🎄🎄 Part $PART"

    gcc -o ./utils/utils.o -c ./utils/utils.c
    gcc -Iutils -Wall -c ./${DAY}/${DAY}part$PART.c -o ./${DAY}/${DAY}part$PART.o
    gcc -o ./${DAY}/${DAY}part$PART ./utils/utils.o ./${DAY}/${DAY}part$PART.o
    cd $DAY
    ./${DAY}part$PART

    cd ..
    echo "\n"
done


