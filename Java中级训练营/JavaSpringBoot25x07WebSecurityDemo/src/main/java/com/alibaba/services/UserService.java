package com.alibaba.services;

import com.alibaba.models.Users;

public interface UserService {
	public Users getUserById(int id);
	public Users getUserByNameAndPassword(String username, String password);
}
