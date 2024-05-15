mkdir tstdir
cd tstdir
mkdir sub-dir

for ii in {1..5}
do

output_file="test-data$ii.txt"

   # 生成随机字符串
rand=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 8)
num_lines=$(( $RANDOM % 100 ))
num_lines=$(( $num_lines * $ii  ))
echo "gen file $output_file  $num_lines"
# 生成数据
for i in $(seq 1 $num_lines); do
    # 生成随机字符串
    rand=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 8)
    # 随机生成数值
    num=$(( $RANDOM % 1000 ))
    # 写入到输出文件
    if (( i % 2 == 0 )); then 
     tstr=LINE
    else
     tstr=line
    fi
    echo "${tstr}${i},${rand},${num}" >> ${output_file}
done

done

cp ./test-data1.txt ./sub-dir/test-data1.txt
ln   ./sub-dir/test-data1.txt ltest-data1
ln -s  ./sub-dir/test-data1.txt stest_data1 

cp ./test-data3.txt ./sub-dir/test-data3.txt
ln   ./sub-dir/test-data3.txt ltest-data3
ln -s  ./sub-dir/test-data3.txt stest_data3 

