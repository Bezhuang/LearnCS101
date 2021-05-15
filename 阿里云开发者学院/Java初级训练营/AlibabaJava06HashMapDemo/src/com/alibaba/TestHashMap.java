package com.alibaba;

import java.util.HashMap;

public class TestHashMap {

	public static void main(String[] args) {
		// 1.Hash��ϣ,ӳ�䣬��ֵ��
		HashMap<Integer, String> hashQQ = new HashMap<Integer, String>();
		hashQQ.put(1000, "Pony");
		hashQQ.put(12314, "׷������");
		hashQQ.put(2434, "���»�");
		// 2.��ȡֵ
		String nickName = hashQQ.get(1000);
		System.out.print(nickName);
		// 3.�����ֻ��ţ���ѯQQ��΢�š�������֧�������Ա��û���Ϣ��User����
		HashMap<String, User> hashApp = new HashMap<String, User>();
		for (int i = 0; i < 100; i++) {
			User user1 = new User();
			user1.ID = "34212312312312414" + i;
			user1.Name = "Pony" + i;
			user1.Password = "12345678" + i;
			user1.NickName = "�����к�" + i;
			user1.Mobie = "136666666" + i;
			user1.City = "����" + i;
			hashApp.put(user1.Mobie, user1);
		}
		// 4.�ֻ��Ų�ѯ�˻���Ϣ
		String key = "13666666666";
		User user2 = hashApp.get(key);
		System.out.println(user2.Name);
		System.out.println(user2.Password);
		System.out.println(user2.NickName);
		System.out.println(user2.City);
		// 5.������д������ӡ�ַ���
		System.out.println(user2.toString());
	}
}
