package com.alibaba;

// 定义用户类
public class User {
	public String ID;// 唯一编号
	public String Name;// 账户
	public String Password;// 密码
	public String NickName;// 昵称
	public String Mobie;// 手机号
	public String City;// 城市
	// 重写
	@Override
	public String toString() {
		return "账户：" + Name + " 密码：" + Password + " 昵称：" + NickName + " 手机：" + Mobie + " 城市： " + City;
	}
}
