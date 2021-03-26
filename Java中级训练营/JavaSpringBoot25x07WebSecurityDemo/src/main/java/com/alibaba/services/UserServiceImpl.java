package com.alibaba.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.alibaba.models.Users;
import com.alibaba.repository.UsersRepository;

@Service
public class UserServiceImpl implements UserService {

	@Autowired
	private UsersRepository usersRepository;
	public Users getUserById(int id)
	{
		if (id>0) {
			return usersRepository.getUserById(id);
		}else {
			return null;
		}		
	}
	public Users getUserByNameAndPassword(String username, String password) {
		// TODO Auto-generated method stub
		return usersRepository.getUserByNameAndPassword(username,password);
	}
}
