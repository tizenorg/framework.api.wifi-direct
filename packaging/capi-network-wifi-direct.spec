Name:       capi-network-wifi-direct
Summary:    Network WiFi-Direct library in Tizen CAPI
Version: 0.0.4
Release:    3
Group:      TO_BE_FILLED
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(dbus-glib-1)
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(vconf)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  cmake

%description

%define debug_package %{nil}  

%package devel 
Summary:    WiFi-Direct library (Shared Library) (Developement)
Group:      TO_BE_FILLED 
Requires: capi-base-common-devel
BuildRequires:  pkgconfig(wifi-direct)
%description devel
WiFi-Direct library (Shared Library) (Developement)

%prep
%setup -q

%build
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix}
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install
mkdir -p %{buildroot}/usr/share/license
cp %{_builddir}/%{buildsubdir}/LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}


%post

%postun

%files
%manifest capi-network-wifi-direct.manifest

%files devel
%defattr(-,root,root,-)
%{_libdir}/pkgconfig/*.pc
%{_includedir}/*/*.h
/usr/share/license/capi-network-wifi-direct
