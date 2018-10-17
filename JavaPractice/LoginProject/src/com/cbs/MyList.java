package com.cbs;

/**
 * 自定义数组队列
 * @author CBS
 */

public class MyList<E> {//使用泛型E
	//声明一个Object数组
	private Object[] array;
	private int size=0;//记录队列中数据类型的长度
	private int initCount=0;//初始化时数组的大小，默认为0
	private int incresCount=1;//数组已满时，每次数组的增长长度
	/**
	 * 构造方法
	 * @param initCount 为数组的初始长度
	 */
	public MyList(int initCount){
		this.initCount=initCount;
		array=new Object[initCount];
	}
	/**
	 * 构造方法
	 * @param initCount 为数组的初始长度
	 * @param incresCount 为数组满是每次的增长长度
	 */
	public MyList(int initCount, int incresCount) {
		this.initCount = initCount;
		this.incresCount = incresCount;
		array=new Object[initCount];
	}

	//实现数据的添加
	public void add(E e){
		if(size<initCount){
			array[size]=e;
		}
		else{
			Object[] newArray=new Object[array.length+incresCount];
			newArray[size]=e;
			for(int i=0;i<array.length;i++){
				newArray[i]=array[i];
			}
			initCount+=incresCount;
			array=newArray;
		}
		size++;
	}
	//实现删除指定下标位置的数据
	public void delete(int i){
		size--;
		initCount--;
		Object[] newArray=new Object[array.length-1];
		for(int j=0;j<i;j++)
			newArray[j]=array[j];
		for(int j=i+1;j<array.length;j++)
			newArray[j-1]=array[j];
		array=newArray;
	}
	//实现插入指定下标位置的数据
	public void insert(E e,int i){
		if(size<initCount && i>=0 && i<size-1){
			for(int j=size;j>i;j--)
				array[j]=array[j-1];
			array[i]=e;
		}
		else{
			Object[] newArray=new Object[array.length+incresCount];
			for(int j=0;j<array.length;j++){
				newArray[j]=array[j];
			}
			initCount+=incresCount;
			array=newArray;
			for(int j=size;j>i;j--)
				array[j]=array[j-1];
			array[i]=e;
		}
		size++;
	}
	//实现获取指定下标位置的数据
	public E get(int i){
		if(i<0 || i>=size)
			return null;
		else
			return (E) array[i];
	}
	//实现更新指定下标位置的数据
	public void upDate(E e,int i){
		if(i>=0 && i<size)
			array[i]=e;
	}
	//获取数组队列中存储的元素个数
	public int legnth(){
		return size;
	}

}
