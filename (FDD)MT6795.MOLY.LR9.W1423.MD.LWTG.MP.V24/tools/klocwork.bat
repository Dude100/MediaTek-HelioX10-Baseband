kwinject.exe -T kwinject_media.trace m r middleware/media
kwinject.exe -t kwinject_media.trace -o kwinject_media.out
kwbuildproject  kwinject_media.out   -o kwtables_media4 -k user.kb
kwadmin create-project media4
kwadmin load media4 kwtables_media4 --copy-sources
