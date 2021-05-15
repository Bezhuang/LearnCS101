package com.alibaba;

import java.util.HashMap;

public class TestHashMap {

	public static void main(String[] args) {
		// 1.Hash哈希,映射，键值对
		HashMap<Integer, String> hashQQ = new HashMap<Integer, String>();
		hashQQ.put(1000, "Pony");
		hashQQ.put(12314, "追风少年");
		hashQQ.put(2434, "刘德华");
		// 2.读取值
		String nickName = hashQQ.get(1000);
		System.out.print(nickName);
		// 3.根据手机号，查询QQ、微信、钉钉、支付宝、淘宝用户信息。User类型
		HashMap<String, User> hashApp = new HashMap<String, User>();
		for (int i = 0; i < 100; i++) {
			User user1 = new User();
			user1.ID = "34212312312312414" + i;
			user1.Name = "Pony" + i;
			user1.Password = "12345678" + i;
			user1.NickName = "阳光男孩" + i;
			user1.Mobie = "136666666" + i;
			user1.City = "火星" + i;
			hashApp.put(user1.Mobie, user1);
		}
		// 4.手机号查询账户信息
		String key = "13666666666";
		User user2 = hashApp.get(key);
		System.out.println(user2.Name);
		System.out.println(user2.Password);
		System.out.println(user2.NickName);
		System.out.println(user2.City);
		// 5.调用重写方法打印字符串
		System.out.println(user2.toString());
	}
}
