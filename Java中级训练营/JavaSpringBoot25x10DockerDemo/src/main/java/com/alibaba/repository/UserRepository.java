package com.alibaba.repository;

import java.util.List;

import com.alibaba.models.User;

public interface UserRepository  {
 
   public List<User> getUserByName(String name);
 
   public User getUserByNameAndPassword(String name,String password);
 
   public User getUserById(int id);
}
