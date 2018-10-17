package com.cbs;

import java.util.regex.Pattern;

/**
 * 分形类 用于生成一个指定迭代次数的分形序列
 */
public class Fractal {
	private String axiom;// 母串
	private String production;// 演变规则

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
	
	//构造函数
	public Fractal(String axiom,String production) throws Exception {
		Pattern pattern=Pattern.compile("[F+-][F+-]*", Pattern.CANON_EQ);
		if(!pattern.matcher(axiom).matches() || !pattern.matcher(production).matches()){
			throw new Exception("母串或演变规则为空，或者包含非法字符！！");
		}
		this.axiom=axiom;
		this.production=production;
	}
	
	//生成指定的迭代序列
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
