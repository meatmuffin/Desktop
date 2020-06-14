if [ ! -d "$1" ] ; then
	echo "未找到相关笔记目录"
else
	rm -rf $1
fi
