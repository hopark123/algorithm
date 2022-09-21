#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unistd.h>
#include <map>
#include <set>

using namespace std;

static size_t		ft_count(char const *s, char c)
{
	size_t		i;
	size_t		cnt;

	i = 0;
	cnt = 0;
	if (s == 0)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		cnt++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (cnt);
}

static size_t		ft_wordlen(char const *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char			*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	char		*result;

	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static void			ft_free(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

char				**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		len;
	size_t		cnt;
	char		**result;

	cnt = ft_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (cnt + 1))) || s == 0)
		return (0);
	i = 0;
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		if (!(result[i] = ft_strndup(s, len)))
		{
			ft_free(result, i);
			return (0);
		}
		s += len;
		i++;
	}
	result[cnt] = 0;
	return (result);
}


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
		map<string, set<string> > mapp;
		map<string, int> map_answer;
		for (vector<string>::iterator it = id_list.begin(); it != id_list.end(); ++it) {
			map_answer.insert(make_pair(*it, 0));
		}

	  for (vector<string>::iterator it=report.begin(); it != report.end(); ++it) {
			char temp[100];
			strcpy(temp, (*it).c_str());
			char **split = ft_split(temp, ' ');
			if (mapp.find(split[1]) != mapp.end()) {
				(mapp.find(split[1]))->second.insert(split[0]);
			}
			else {
				set<string> temp;
				temp.insert(split[0]);
				string one = split[1];
				mapp.insert(make_pair(one, temp));
			}
		}
		for (map<string, set<string> >::iterator it = mapp.begin(); it != mapp.end(); ++it) {
			if (it->second.size() >= k) {
				for (set<string>::iterator itt = it->second.begin(); itt != it->second.end(); ++itt) {
						++map_answer.find(*itt)->second;
				}
			}
		}
		for (vector<string>::iterator it = id_list.begin(); it != id_list.end(); ++it) {
			answer.push_back(map_answer.find(*it)->second);
		}

    return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  vector<string> b;
  vector<string> c;
  b.push_back("muzi");
  b.push_back("frodo");
  b.push_back("apeach");
  b.push_back("neo");
  
  c.push_back("muzi frodo");
  c.push_back("apeach frodo");
  c.push_back("frodo neo");
  c.push_back("muzi neo");
  c.push_back("apeach muzi");
  vector<int> a = solution(b, c, 2);
  for (vector<int>::iterator it=a.begin(); it != a.end(); ++it)
    cout << *it << endl;
}