package com.cbs;

/**
 * �Զ����������
 * @author CBS
 */

public class MyList<E> {//ʹ�÷���E
	//����һ��Object����
	private Object[] array;
	private int size=0;//��¼�������������͵ĳ���
	private int initCount=0;//��ʼ��ʱ����Ĵ�С��Ĭ��Ϊ0
	private int incresCount=1;//��������ʱ��ÿ���������������
	/**
	 * ���췽��
	 * @param initCount Ϊ����ĳ�ʼ����
	 */
	public MyList(int initCount){
		this.initCount=initCount;
		array=new Object[initCount];
	}
	/**
	 * ���췽��
	 * @param initCount Ϊ����ĳ�ʼ����
	 * @param incresCount Ϊ��������ÿ�ε���������
	 */
	public MyList(int initCount, int incresCount) {
		this.initCount = initCount;
		this.incresCount = incresCount;
		array=new Object[initCount];
	}

	//ʵ�����ݵ����
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
	//ʵ��ɾ��ָ���±�λ�õ�����
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
	//ʵ�ֲ���ָ���±�λ�õ�����
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
	//ʵ�ֻ�ȡָ���±�λ�õ�����
	public E get(int i){
		if(i<0 || i>=size)
			return null;
		else
			return (E) array[i];
	}
	//ʵ�ָ���ָ���±�λ�õ�����
	public void upDate(E e,int i){
		if(i>=0 && i<size)
			array[i]=e;
	}
	//��ȡ��������д洢��Ԫ�ظ���
	public int legnth(){
		return size;
	}

}
