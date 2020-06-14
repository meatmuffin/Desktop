if [ ! -f "$1" ] ; then
   echo "未找到相关笔记，请检查路径"
else
   gedit $1
fi
