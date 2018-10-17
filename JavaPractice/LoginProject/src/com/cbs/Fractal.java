package com.cbs;

import java.util.regex.Pattern;

/**
 * ������ ��������һ��ָ�����������ķ�������
 */
public class Fractal {
	private String axiom;// ĸ��
	private String production;// �ݱ����

	public String getAxiom() {
		return axiom;
	}

	public void setAxiom(String axiom) {
		this.axiom = axiom;
	}

	public String getProduction() {
		return production;
	}

	public void setProduction(String production) {
		this.production = production;
	}
	
	//���캯��
	public Fractal(String axiom,String production) throws Exception {
		Pattern pattern=Pattern.compile("[F+-][F+-]*", Pattern.CANON_EQ);
		if(!pattern.matcher(axiom).matches() || !pattern.matcher(production).matches()){
			throw new Exception("ĸ�����ݱ����Ϊ�գ����߰����Ƿ��ַ�����");
		}
		this.axiom=axiom;
		this.production=production;
	}
	
	//����ָ���ĵ�������
	public String generate(int count){
		if(count==0)
			return axiom;
		String sequence=axiom;
		for(int i=0;i<count;i++){
			StringBuffer sbuf=new StringBuffer();
			for(int j=0;j<sequence.length();j++){
				if(sequence.charAt(j)=='F'){
					sbuf.append(production);
				}else{
					sbuf.append(sequence.charAt(j));
				}
			}
			sequence=sbuf.toString();
		}
		return sequence;
	}

}
