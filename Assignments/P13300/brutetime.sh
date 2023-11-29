g++ BasicBruteTest.cpp -o Main
TIME=$(($(date +%s%N)/1000000))
./Main < biginput > bigoutput
NEWTIME=$(($(date +%s%N)/1000000))
DELTA=$(($NEWTIME-$TIME))
echo $DELTA
