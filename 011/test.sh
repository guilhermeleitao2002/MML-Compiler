cd ../co23
rm -rf checked-out*
mkdir checked-out
cp -r ../011 checked-out/011
mkdir checked-out-ref/
mkdir checked-out-ref/011
./test-group.sh 011

