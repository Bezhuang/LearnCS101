package com.alibaba;

// �����û���
public class User {
	public String ID;// Ψһ���
	public String Name;// �˻�
	public String Password;// ����
	public String NickName;// �ǳ�
	public String Mobie;// �ֻ���
	public String City;// ����
	// ��д
	@Override
	public String toString() {
		return "�˻���" + Name + " ���룺" + Password + " �ǳƣ�" + NickName + " �ֻ���" + Mobie + " ���У� " + City;
	}
}
