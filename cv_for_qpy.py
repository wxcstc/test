#coding=utf-8
#qpy:console
#qpy:2

import urllib2,os

hurl='http://www.liyuanrui.com/opencv/'

def wf(filename):
    url=hurl+filename
    ff=urllib2.urlopen(url)
    fr=ff.read()
    ff.close()
    f=open(filename,'wb')
    f.write(fr)
    f.close()
    os.system('chmod 755 %s'%filename)


#chdir $PYTHONHOME
pythonhome=os.popen('echo $PYTHONHOME').read().strip('\n')
print '\nchdir %s'%pythonhome
os.chdir(pythonhome)

#lib
libs=['libnative_camera_r4.4.0.so', 'libnative_camera_r4.3.0.so', 'libnative_camera_r4.2.0.so', 'libnative_camera_r4.1.1.so', 'libnative_camera_r4.0.3.so', 'libnative_camera_r4.0.0.so', 'libnative_camera_r3.0.1.so', 'libnative_camera_r2.3.3.so', 'libnative_camera_r2.2.0.so']
print 'chdir lib'
os.chdir('lib')
for filename in libs:
    print 'download %s'%filename
    wf(filename)

#site-packages
packages=['cv2.so', 'cv.pyo']
print 'chdir python2.7/site-packages'
os.chdir('python2.7/site-packages')
for filename in packages:
    print 'download %s'%filename
    wf(filename)

#lib-dynload
dynload=['imageop.so']
print 'chdir lib-dynload'
os.chdir('../lib-dynload')
for filename in dynload:
    print 'download %s'%filename
    wf(filename)

print 'Successful install opencv'
try:
    import numpy
except:
    print 'if you want to use cv2,please install numpy by index moudle control'