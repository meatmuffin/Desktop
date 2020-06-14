if [ ! -f "$1" ] ; then
	echo "未找到相关笔记"
else
	rm $1
fi
