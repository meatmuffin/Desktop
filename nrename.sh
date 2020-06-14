if [ ! -f "$1" ] ; then
   echo "未找到相关笔记"
else
   mv $1 $2
fi
