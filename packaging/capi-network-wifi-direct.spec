Name:       capi-network-wifi-direct
Summary:    Network WiFi-Direct library in Tizen CAPI
Version: 0.0.1
Release:    3
Group:      TO_BE_FILLED
License:    TO_BE_FILLED
Source0:    %{name}-%{version}.tar.gz
Source1001: packaging/capi-network-wifi-direct.manifest 
BuildRequires:  pkgconfig(dbus-glib-1)
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(vconf)
BuildRequires:  pkgconfig(wifi-direct)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  cmake

%description

%define debug_package %{nil}  

%package devel 
Summary:    WiFi-Direct library (Shared Library) (Developement)
Group:      TO_BE_FILLED 
Requires:  pkgconfig(capi-base-common)
Requires:  pkgconfig(wifi-direct)

%description devel
WiFi-Direct library (Shared Library) (Developement)

%prep
%setup -q

%build
cp %{SOURCE1001} .
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix}
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

%post

%postun

%files devel 
%manifest capi-network-wifi-direct.manifest
%defattr(-,root,root,-)
%{_libdir}/pkgconfig/*.pc
%{_includedir}/*/*.h
