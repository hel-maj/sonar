/* ===== 23c636410 license.license_client:369 ===== */
/* ghidra_name=FUN_23c636410 entry=23c636410 size=3218 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c636410(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  code *pcVar15;
  undefined4 uVar16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  undefined8 uStack_110;
  undefined8 uStack_108;
  longlong *plStack_100;
  longlong *plStack_e8;
  longlong lStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong **pplStack_c0;
  undefined8 *puStack_b8;
  longlong *plStack_b0;
  undefined8 uStack_80;
  longlong *plStack_78;
  code *pcStack_70;
  longlong *plStack_68;
  
  plVar6 = _DAT_23ee29c60;
  plVar12 = (longlong *)*param_3;
  plVar1 = (longlong *)param_3[1];
  if (_DAT_23ee29c60 == (longlong *)0x0) {
LAB_23c636453:
    plStack_b0 = (longlong *)0x23c63646f;
    _DAT_23ee29c60 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c58,DAT_23ee29d18,0x10);
  }
  else {
    lVar8 = *_DAT_23ee29c60;
    if (1 < lVar8) {
      *_DAT_23ee29c60 = lVar8 + -1;
      goto LAB_23c636453;
    }
    if (_DAT_23ee29c60[2] != 0) {
      *_DAT_23ee29c60 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        plStack_b0 = (longlong *)0x23c636ac2;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23c636453;
    }
  }
  plVar13 = _DAT_23ee29c60;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23ee29c60 + 9;
  lVar10 = *(longlong *)(lVar8 + 8);
  _DAT_23ee29c60[0xf] = lVar10;
  *(longlong **)(lVar8 + 8) = plVar6;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar13[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar13[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar13 = *plVar13 + 1;
  uVar18 = _DAT_23ee283b8;
  *(undefined4 *)(plVar13 + 8) = 0;
  plStack_b0 = (longlong *)0x23c6364e5;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar12,uVar18);
  if (plVar6 == (longlong *)0x0) goto LAB_23c636ad0;
  plStack_b0 = (longlong *)0x23c6364f9;
  iVar5 = FUN_23a35f020(plVar6);
  lVar8 = *plVar6 + -1;
  if (iVar5 == -1) {
    plVar7 = *(longlong **)(param_1 + 0x60);
    pcVar15 = *(code **)(param_1 + 0x68);
    uVar20 = 0x178;
    uVar16 = 0x178;
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar6 = lVar8;
joined_r0x00023c636db8:
    plVar11 = DAT_23ed6a4f8;
    plVar3 = uStack_80;
    if (lVar8 == 0) {
      uStack_80._4_4_ = (undefined4)((ulonglong)uStack_80 >> 0x20);
      uStack_80 = (longlong *)CONCAT44(uStack_80._4_4_,uVar16);
      plStack_b0 = (longlong *)0x23c636dcd;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
      uVar20 = SUB84(uStack_80,0);
      plVar11 = DAT_23ed6a4f8;
      plVar3 = uStack_80;
    }
    goto joined_r0x00023c636af5;
  }
  *plVar6 = lVar8;
  if (lVar8 == 0) {
    plStack_b0 = (longlong *)0x23c63692a;
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if (iVar5 != 0) {
    plStack_b0 = (longlong *)0x23c636942;
    plVar6 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23ee283b8);
    if (plVar6 != (longlong *)0x0) {
      *(undefined4 *)(plVar13 + 5) = 0x178;
      plStack_b0 = (longlong *)0x23c636967;
      plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,_DAT_23ee288b8);
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        plStack_b0 = (longlong *)0x23c63697f;
        uStack_80 = plVar7;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
        plVar7 = uStack_80;
      }
      if (plVar7 != (longlong *)0x0) {
        plStack_b0 = (longlong *)0x23c63699a;
        uStack_80 = plVar7;
        iVar5 = FUN_23a35f020(plVar7);
        lVar8 = *uStack_80 + -1;
        if (iVar5 == -1) {
          plVar7 = *(longlong **)(param_1 + 0x60);
          pcVar15 = *(code **)(param_1 + 0x68);
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *uStack_80 = lVar8;
          if (lVar8 == 0) {
            plStack_b0 = (longlong *)0x23c636eae;
            (**(code **)(uStack_80[1] + 0x30))(uStack_80);
          }
          uVar20 = 0x178;
          plVar11 = DAT_23ed6a4f8;
          plVar3 = uStack_80;
          goto joined_r0x00023c636af5;
        }
        *uStack_80 = lVar8;
        if (lVar8 == 0) {
          plStack_b0 = (longlong *)0x23c6369c3;
          (**(code **)(uStack_80[1] + 0x30))(uStack_80);
        }
        if (iVar5 == 1) {
          plStack_b0 = (longlong *)0x23c6369d1;
          lVar10 = FUN_23ead5f40();
          lVar8 = _DAT_23ee288c0;
          if (lVar10 != 0) {
            *(undefined4 *)(plVar13 + 5) = 0x179;
            plStack_b0 = (longlong *)0x23c6369fe;
            plVar6 = (longlong *)
                     FUN_23e915840(param_1,lVar10,_DAT_23ee28548,*(undefined8 *)(lVar8 + 0x18));
            if (plVar6 == (longlong *)0x0) {
              plVar7 = *(longlong **)(param_1 + 0x60);
              uVar20 = 0x179;
              plVar9 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar15 = *(code **)(param_1 + 0x68);
              plVar11 = DAT_23ed6a4f8;
              plVar3 = uStack_80;
              goto joined_r0x00023c636af5;
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              plStack_b0 = (longlong *)0x23c636a17;
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            pcVar15 = _Py_NoneStruct_exref;
            lVar8 = *(longlong *)(param_1 + 0x38);
            lVar10 = *(longlong *)(lVar8 + 8);
            *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
            plVar6 = *(longlong **)(lVar10 + 0x28);
            plVar13 = (longlong *)plVar6[2];
            *(undefined8 *)(lVar8 + 8) = *(undefined8 *)(lVar10 + 0x30);
            *(undefined4 *)(plVar6 + 8) = 0xffffffff;
            if (plVar13 != (longlong *)0x0) {
              plVar6[2] = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                plStack_b0 = (longlong *)0x23c636a5b;
                (**(code **)(plVar13[1] + 0x30))();
              }
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              plStack_b0 = (longlong *)0x23c636a6b;
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            plVar6[0xf] = 0;
            goto LAB_23c636a73;
          }
          plStack_b0 = (longlong *)0x23c636f64;
          FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
          uVar20 = 0x179;
          plVar7 = plStack_78;
          pcVar15 = pcStack_70;
          plVar9 = plStack_68;
          plVar11 = DAT_23ed6a4f8;
          plVar3 = uStack_80;
          goto joined_r0x00023c636af5;
        }
        goto LAB_23c636522;
      }
    }
LAB_23c636ad0:
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x178;
    plVar7 = *(longlong **)(param_1 + 0x60);
    pcVar15 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = DAT_23ed6a4f8;
    plVar3 = uStack_80;
    goto joined_r0x00023c636af5;
  }
LAB_23c636522:
  plStack_b0 = (longlong *)0x23c636534;
  cVar4 = FUN_23e8d9ac0(plVar12,_DAT_23ee283e8,plVar1);
  if (cVar4 == '\0') {
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar7 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar20 = 0x17c;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar15 = *(code **)(param_1 + 0x68);
    plVar11 = DAT_23ed6a4f8;
    plVar3 = uStack_80;
    goto joined_r0x00023c636af5;
  }
  plStack_b0 = (longlong *)0x23c63654b;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23ee283d0);
  if (plVar6 != (longlong *)0x0) {
    plStack_b0 = (longlong *)0x23c636566;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23ee288c8);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      plStack_b0 = (longlong *)0x23c636d5a;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    if (plVar7 != (longlong *)0x0) {
      *(undefined4 *)(plVar13 + 5) = 0x17d;
      plStack_b0 = (longlong *)0x23c63658e;
      plVar6 = (longlong *)FUN_23e91a870(param_1,plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        plStack_b0 = (longlong *)0x23c6365a2;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar6 != (longlong *)0x0) {
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          plStack_b0 = (longlong *)0x23c6365bb;
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        plStack_b0 = (longlong *)0x23c6365c0;
        lVar8 = FUN_23ead6090();
        if (lVar8 == 0) {
          plStack_b0 = (longlong *)0x23c636f94;
          FUN_23e915740(param_1,&plStack_78,_DAT_23ee283c0);
          uVar20 = 0x17f;
          plVar7 = plStack_78;
          pcVar15 = pcStack_70;
          plVar9 = plStack_68;
          plVar11 = DAT_23ed6a4f8;
          plVar3 = uStack_80;
          goto joined_r0x00023c636af5;
        }
        plStack_b0 = (longlong *)0x23c6365d8;
        plVar6 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23ee288d0);
        if (plVar6 == (longlong *)0x0) goto LAB_23c636de0;
        plStack_b0 = (longlong *)0x23c6365f3;
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23ee288d8);
        pcVar15 = _Py_TrueStruct_exref;
        plVar7 = _DAT_23ee288e0;
        if (plVar9 == (longlong *)0x0) {
          plVar7 = *(longlong **)(param_1 + 0x60);
          pcVar15 = *(code **)(param_1 + 0x68);
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            plStack_b0 = (longlong *)0x23c636f3c;
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          uVar20 = 0x180;
          plVar11 = DAT_23ed6a4f8;
          plVar3 = uStack_80;
          goto joined_r0x00023c636af5;
        }
        *(undefined4 *)(plVar13 + 5) = 0x17f;
        pcStack_70 = pcVar15;
        plStack_68 = plVar7;
        plStack_b0 = (longlong *)0x23c63663d;
        plStack_78 = plVar9;
        plVar7 = (longlong *)FUN_23e9186b0(param_1,plVar6,&plStack_78,_DAT_23ee288e8);
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          plStack_b0 = (longlong *)0x23c636650;
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          plStack_b0 = (longlong *)0x23c636660;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar7 != (longlong *)0x0) {
          plStack_b0 = (longlong *)0x23c63667b;
          cVar4 = FUN_23e8d9ac0(plVar12,_DAT_23ee283b8,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            plStack_b0 = (longlong *)0x23c63668d;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (cVar4 != '\0') {
            plStack_b0 = (longlong *)0x23c6366a5;
            plVar6 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23ee283b8);
            if (plVar6 != (longlong *)0x0) {
              *(undefined4 *)(plVar13 + 5) = 0x184;
              plStack_b0 = (longlong *)0x23c6366ca;
              plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,_DAT_23ee288f0);
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                plStack_b0 = (longlong *)0x23c636e3a;
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              if (plVar7 != (longlong *)0x0) {
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  plStack_b0 = (longlong *)0x23c636e4a;
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                plStack_b0 = (longlong *)0x23c6366ef;
                lVar8 = FUN_23ead5f40();
                if (lVar8 == 0) {
                  plStack_b0 = (longlong *)0x23c6370a7;
                  FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
                  uVar20 = 0x186;
                  plVar7 = plStack_78;
                  pcVar15 = pcStack_70;
                  plVar9 = plStack_68;
                  plVar11 = DAT_23ed6a4f8;
                  plVar3 = uStack_80;
                  goto joined_r0x00023c636af5;
                }
                plStack_b0 = (longlong *)0x23c636707;
                plVar6 = (longlong *)FUN_23e8bc2f0(lVar8,DAT_23ee28400);
                plVar7 = _DAT_23ee288f8;
                if (plVar6 == (longlong *)0x0) {
LAB_23c636e50:
                  plVar7 = *(longlong **)(param_1 + 0x60);
                  uVar20 = 0x186;
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar15 = *(code **)(param_1 + 0x68);
                  plVar11 = DAT_23ed6a4f8;
                  plVar3 = uStack_80;
                }
                else {
                  lVar8 = *(longlong *)(param_1 + 0x10);
                  plVar9 = *(longlong **)(lVar8 + 0xe28);
                  if (plVar9 == (longlong *)0x0) {
                    plStack_b0 = (longlong *)0x23c637051;
                    plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar10 = plVar9[3];
                    *(int *)(lVar8 + 0xec0) = *(int *)(lVar8 + 0xec0) + -1;
                    *(longlong *)(lVar8 + 0xe28) = lVar10;
                    *plVar9 = 1;
                  }
                  pcVar15 = _PyRuntime_exref;
                  *(undefined1 (*) [16])(plVar9 + 4) = (undefined1  [16])0x0;
                  lVar8 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
                  lVar10 = plVar9[-1];
                  puVar17 = *(undefined8 **)(lVar8 + 8);
                  *puVar17 = plVar9 + -2;
                  plVar9[-2] = lVar8;
                  plVar9[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar17;
                  *(longlong **)(lVar8 + 8) = plVar9 + -2;
                  uVar18 = _DAT_23ee28900;
                  *plVar7 = *plVar7 + 1;
                  plVar9[3] = (longlong)plVar7;
                  plStack_b0 = (longlong *)0x23c6367b1;
                  uStack_80 = plVar9;
                  plVar7 = (longlong *)FUN_23e8bc2f0(plVar12,uVar18);
                  pcVar15 = DAT_23ed6cd28;
                  if (plVar7 != (longlong *)0x0) {
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plStack_b0 = (longlong *)0x23c637075;
                      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar9 == (longlong *)0x0) {
                        plStack_b0 = (longlong *)0x23c6370fa;
                        PyErr_PrintEx(0);
                        lVar8 = 1;
                        plStack_b0 = (longlong *)0x23c637105;
                        Py_Exit();
                        plVar11 = _DAT_23ee29c50;
                        puStack_b8 = &DAT_23ed6cce0;
                        plVar9 = (longlong *)*puVar17;
                        plStack_e8 = plVar13;
                        lStack_e0 = param_1;
                        plStack_d8 = plVar6;
                        plStack_d0 = plVar12;
                        plStack_c8 = plVar1;
                        pplStack_c0 = &plStack_78;
                        plStack_b0 = plVar7;
                        if (_DAT_23ee29c50 == (longlong *)0x0) {
LAB_23c63714a:
                          _DAT_23ee29c50 =
                               (longlong *)FUN_23e91f3b0(lVar8,_DAT_23ee29c48,DAT_23ee29d18,8);
                        }
                        else {
                          lVar10 = *_DAT_23ee29c50;
                          if (1 < lVar10) {
                            *_DAT_23ee29c50 = lVar10 + -1;
                            goto LAB_23c63714a;
                          }
                          if (_DAT_23ee29c50[2] != 0) {
                            *_DAT_23ee29c50 = lVar10 + -1;
                            if (lVar10 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            goto LAB_23c63714a;
                          }
                        }
                        plVar1 = _DAT_23ee29c50;
                        lVar10 = *(longlong *)(lVar8 + 0x38);
                        plVar12 = _DAT_23ee29c50 + 9;
                        lVar14 = *(longlong *)(lVar10 + 8);
                        _DAT_23ee29c50[0xf] = lVar14;
                        *(longlong **)(lVar10 + 8) = plVar12;
                        if (((lVar14 != 0) &&
                            ((*(char *)(lVar14 + 0x45) == '\x01' ||
                             ((ulonglong)
                              (*(longlong *)(lVar14 + 0x20) + 0xb8 +
                              (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
                              *(ulonglong *)(lVar14 + 0x38))))) && (plVar1[0xe] != 0)) {
                          plVar12 = *(longlong **)(lVar14 + 0x28);
                          *(longlong **)(plVar1[0xe] + 0x10) = plVar12;
                          if (plVar12 != (longlong *)0x0) {
                            *plVar12 = *plVar12 + 1;
                          }
                        }
                        *plVar1 = *plVar1 + 1;
                        uVar18 = _DAT_23ee283b8;
                        *(undefined4 *)(plVar1 + 8) = 0;
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar9,uVar18);
                        if (plVar12 != (longlong *)0x0) {
                          iVar5 = FUN_23a35f020(plVar12);
                          lVar10 = *plVar12 + -1;
                          if (iVar5 == -1) {
                            uVar18 = *(undefined8 *)(lVar8 + 0x60);
                            uVar19 = *(undefined8 *)(lVar8 + 0x68);
                            uVar20 = 0x18a;
                            plVar6 = *(longlong **)(lVar8 + 0x70);
                            *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(lVar8 + 0x70) = 0;
                            *plVar12 = lVar10;
                            if (lVar10 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            goto LAB_23c637502;
                          }
                          *plVar12 = lVar10;
                          if (lVar10 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if (iVar5 == 0) {
LAB_23c637219:
                            lVar10 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 8);
                            plVar12 = *(longlong **)(lVar10 + 0x28);
                            plVar1 = (longlong *)plVar12[2];
                            *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8) =
                                 *(undefined8 *)(lVar10 + 0x30);
                            *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                            if (plVar1 != (longlong *)0x0) {
                              plVar12[2] = 0;
                              *plVar1 = *plVar1 + -1;
                              if (*plVar1 == 0) {
                                (**(code **)(plVar1[1] + 0x30))();
                              }
                            }
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            plVar12[0xf] = 0;
                            pcVar15 = _Py_NoneStruct_exref;
                            *(longlong *)_Py_NoneStruct_exref =
                                 *(longlong *)_Py_NoneStruct_exref + 1;
                            *plVar9 = *plVar9 + -1;
                            if (*plVar9 != 0) {
                              return pcVar15;
                            }
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                            return pcVar15;
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23ee283b8);
                          if (plVar12 != (longlong *)0x0) {
                            *(undefined4 *)(plVar1 + 5) = 0x18a;
                            plVar13 = (longlong *)FUN_23e91bfe0(lVar8,plVar12,_DAT_23ee288b8);
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            if (plVar13 != (longlong *)0x0) {
                              iVar5 = FUN_23a35f020(plVar13);
                              lVar10 = *plVar13 + -1;
                              if (iVar5 == -1) {
                                uVar18 = *(undefined8 *)(lVar8 + 0x60);
                                uVar19 = *(undefined8 *)(lVar8 + 0x68);
                                plVar6 = *(longlong **)(lVar8 + 0x70);
                                *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar8 + 0x70) = 0;
                                *plVar13 = lVar10;
                                if (lVar10 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                                }
                                uVar20 = 0x18a;
                              }
                              else {
                                *plVar13 = lVar10;
                                if (lVar10 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                                }
                                if (iVar5 != 1) goto LAB_23c637219;
                                lVar14 = FUN_23ead5f40();
                                lVar10 = _DAT_23ee28918;
                                if (lVar14 == 0) {
                                  uVar20 = 0x18b;
                                  FUN_23e915740(lVar8,&uStack_110,DAT_23ee283f8);
                                  uVar18 = uStack_110;
                                  uVar19 = uStack_108;
                                  plVar6 = plStack_100;
                                }
                                else {
                                  *(undefined4 *)(plVar1 + 5) = 0x18b;
                                  plVar12 = (longlong *)
                                            FUN_23e915840(lVar8,lVar14,DAT_23ee28400,
                                                          *(undefined8 *)(lVar10 + 0x18));
                                  if (plVar12 == (longlong *)0x0) {
                                    uVar18 = *(undefined8 *)(lVar8 + 0x60);
                                    uVar20 = 0x18b;
                                    plVar6 = *(longlong **)(lVar8 + 0x70);
                                    *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(lVar8 + 0x70) = 0;
                                    uVar19 = *(undefined8 *)(lVar8 + 0x68);
                                  }
                                  else {
                                    *plVar12 = *plVar12 + -1;
                                    if (*plVar12 == 0) {
                                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                                    }
                                    plVar12 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23ee283d0);
                                    if (plVar12 != (longlong *)0x0) {
                                      *(undefined4 *)(plVar1 + 5) = 0x18c;
                                      plVar6 = (longlong *)
                                               FUN_23e91bfe0(lVar8,plVar12,_DAT_23ee28920);
                                      *plVar12 = *plVar12 + -1;
                                      if (*plVar12 == 0) {
                                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                                      }
                                      if (plVar6 != (longlong *)0x0) {
                                        *plVar6 = *plVar6 + -1;
                                        if (*plVar6 == 0) {
                                          (**(code **)(plVar6[1] + 0x30))(plVar6);
                                        }
                                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23ee283b8);
                                        if (plVar12 != (longlong *)0x0) {
                                          plVar6 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23ee28928)
                                          ;
                                          *plVar12 = *plVar12 + -1;
                                          if (*plVar12 == 0) {
                                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                                          }
                                          lVar10 = _DAT_23ee28930;
                                          if (plVar6 != (longlong *)0x0) {
                                            *(undefined4 *)(plVar1 + 5) = 0x18d;
                                            plVar12 = (longlong *)
                                                      FUN_23e9186b0(lVar8,plVar6,lVar10 + 0x18,
                                                                    _DAT_23ee28938);
                                            *plVar6 = *plVar6 + -1;
                                            if (*plVar6 == 0) {
                                              (**(code **)(plVar6[1] + 0x30))(plVar6);
                                            }
                                            if (plVar12 != (longlong *)0x0) {
                                              *plVar12 = *plVar12 + -1;
                                              if (*plVar12 == 0) {
                                                (**(code **)(plVar12[1] + 0x30))(plVar12);
                                              }
                                              lVar14 = FUN_23ead5f40();
                                              lVar10 = _DAT_23ee28940;
                                              if (lVar14 == 0) {
                                                uVar20 = 0x18e;
                                                FUN_23e915740(lVar8,&uStack_110,DAT_23ee283f8);
                                                uVar18 = uStack_110;
                                                uVar19 = uStack_108;
                                                plVar6 = plStack_100;
                                              }
                                              else {
                                                *(undefined4 *)(plVar1 + 5) = 0x18e;
                                                plVar12 = (longlong *)
                                                          FUN_23e915840(lVar8,lVar14,DAT_23ee28400,
                                                                        *(undefined8 *)
                                                                         (lVar10 + 0x18));
                                                if (plVar12 != (longlong *)0x0) {
                                                  *plVar12 = *plVar12 + -1;
                                                  if (*plVar12 == 0) {
                                                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                                                  }
                                                  goto LAB_23c637219;
                                                }
                                                uVar18 = *(undefined8 *)(lVar8 + 0x60);
                                                uVar20 = 0x18e;
                                                plVar6 = *(longlong **)(lVar8 + 0x70);
                                                *(undefined1 (*) [16])(lVar8 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *(undefined8 *)(lVar8 + 0x70) = 0;
                                                uVar19 = *(undefined8 *)(lVar8 + 0x68);
                                              }
                                              goto LAB_23c637502;
                                            }
                                          }
                                        }
                                        uVar18 = *(undefined8 *)(lVar8 + 0x60);
                                        uVar20 = 0x18d;
                                        plVar6 = *(longlong **)(lVar8 + 0x70);
                                        *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0
                                        ;
                                        *(undefined8 *)(lVar8 + 0x70) = 0;
                                        uVar19 = *(undefined8 *)(lVar8 + 0x68);
                                        goto LAB_23c637502;
                                      }
                                    }
                                    uVar18 = *(undefined8 *)(lVar8 + 0x60);
                                    uVar20 = 0x18c;
                                    plVar6 = *(longlong **)(lVar8 + 0x70);
                                    *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(lVar8 + 0x70) = 0;
                                    uVar19 = *(undefined8 *)(lVar8 + 0x68);
                                  }
                                }
                              }
                              goto LAB_23c637502;
                            }
                          }
                        }
                        plVar6 = *(longlong **)(lVar8 + 0x70);
                        *(undefined8 *)(lVar8 + 0x70) = 0;
                        uVar20 = 0x18a;
                        uVar18 = *(undefined8 *)(lVar8 + 0x60);
                        uVar19 = *(undefined8 *)(lVar8 + 0x68);
                        *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
LAB_23c637502:
                        plVar12 = DAT_23ed6a4f8;
                        if (plVar6 == (longlong *)0x0) {
                          if (DAT_23ed6a4f8 == (longlong *)0x0) {
                            plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                          }
                          else {
                            plVar6 = (longlong *)*DAT_23ed6a4f8;
                            *DAT_23ed6a4f8 = 1;
                            DAT_23ed6a4f8 = plVar6;
                            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                          }
                          pcVar15 = _PyRuntime_exref;
                          plVar12[2] = 0;
                          plVar12[3] = (longlong)plVar1;
                          *plVar1 = *plVar1 + 1;
                          lVar10 = *(longlong *)(pcVar15 + 0x1f8);
                          *(undefined4 *)(plVar12 + 4) = 0xffffffff;
                          lVar10 = *(longlong *)(lVar10 + 0x10);
                          *(undefined4 *)((longlong)plVar12 + 0x24) = uVar20;
                          lVar10 = *(longlong *)(lVar10 + 0x2e8);
                          lVar14 = plVar12[-1];
                          puVar17 = *(undefined8 **)(lVar10 + 8);
                          *puVar17 = plVar12 + -2;
                          plVar12[-2] = lVar10;
                          plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar17;
                          *(longlong **)(lVar10 + 8) = plVar12 + -2;
                          plVar13 = plVar12;
                        }
                        else {
                          plVar13 = plVar6;
                          if ((longlong *)plVar6[3] != plVar1) {
                            if (DAT_23ed6a4f8 == (longlong *)0x0) {
                              plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                            }
                            else {
                              plVar13 = (longlong *)*DAT_23ed6a4f8;
                              *DAT_23ed6a4f8 = 1;
                              DAT_23ed6a4f8 = plVar13;
                              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                            }
                            pcVar15 = _PyRuntime_exref;
                            plVar12[3] = (longlong)plVar1;
                            *plVar1 = *plVar1 + 1;
                            lVar10 = *(longlong *)(pcVar15 + 0x1f8);
                            *(undefined4 *)(plVar12 + 4) = 0xffffffff;
                            *(undefined4 *)((longlong)plVar12 + 0x24) = uVar20;
                            lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
                            lVar14 = plVar12[-1];
                            puVar17 = *(undefined8 **)(lVar10 + 8);
                            *puVar17 = plVar12 + -2;
                            plVar12[-2] = lVar10;
                            plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar17;
                            lVar14 = *plVar6;
                            *(longlong **)(lVar10 + 8) = plVar12 + -2;
                            plVar12[2] = (longlong)plVar6;
                            plVar13 = plVar12;
                            if (lVar14 == 0) {
                              (**(code **)(plVar6[1] + 0x30))(plVar6);
                            }
                          }
                        }
                        FUN_23e8bba40(plVar1,&DAT_23ec47964,plVar9);
                        if (_DAT_23ee29c50 == plVar1) {
                          *plVar1 = *plVar1 + -1;
                          if (*plVar1 == 0) {
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                          }
                          _DAT_23ee29c50 = (longlong *)0x0;
                        }
                        lVar10 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 8);
                        plVar12 = *(longlong **)(lVar10 + 0x28);
                        plVar1 = (longlong *)plVar12[2];
                        *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8) =
                             *(undefined8 *)(lVar10 + 0x30);
                        *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                        if (plVar1 != (longlong *)0x0) {
                          plVar12[2] = 0;
                          *plVar1 = *plVar1 + -1;
                          if (*plVar1 == 0) {
                            (**(code **)(plVar1[1] + 0x30))();
                          }
                        }
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        plVar12[0xf] = 0;
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        FUN_23a33aa70(lVar8,uVar18,uVar19,plVar13);
                        return (code *)0x0;
                      }
                      *plVar9 = *plVar9 + 1;
                      DAT_23ed6a4c0 = plVar9;
                    }
                    pcStack_70 = pcVar15;
                    plStack_b0 = (longlong *)0x23c6367fb;
                    plStack_78 = plVar7;
                    lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_78);
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      plStack_b0 = (longlong *)0x23c636813;
                      (**(code **)(plVar7[1] + 0x30))(plVar7);
                    }
                    plVar7 = _DAT_23ee28908;
                    if (lVar8 != 0) {
                      uStack_80[4] = lVar8;
                      *plVar7 = *plVar7 + 1;
                      uStack_80[5] = (longlong)plVar7;
                      plStack_b0 = (longlong *)0x23c636846;
                      plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,uStack_80);
                      *uStack_80 = *uStack_80 + -1;
                      if (*uStack_80 == 0) {
                        plStack_b0 = (longlong *)0x23c63685e;
                        (**(code **)(uStack_80[1] + 0x30))(uStack_80);
                      }
                      if (plVar7 == (longlong *)0x0) {
                        plVar7 = *(longlong **)(param_1 + 0x60);
                        pcVar15 = *(code **)(param_1 + 0x68);
                        uVar20 = 0x186;
                        uVar16 = 0x186;
                        plVar9 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *plVar6 = *plVar6 + -1;
                        lVar8 = *plVar6;
                        goto joined_r0x00023c636db8;
                      }
                      *(undefined4 *)(plVar13 + 5) = 0x186;
                      plStack_b0 = (longlong *)0x23c63687c;
                      plVar9 = (longlong *)FUN_23e914090(param_1,plVar6,plVar7);
                      *plVar6 = *plVar6 + -1;
                      if (*plVar6 == 0) {
                        plStack_b0 = (longlong *)0x23c63688f;
                        (**(code **)(plVar6[1] + 0x30))(plVar6);
                      }
                      *plVar7 = *plVar7 + -1;
                      if (*plVar7 == 0) {
                        plStack_b0 = (longlong *)0x23c6368a0;
                        (**(code **)(plVar7[1] + 0x30))(plVar7);
                      }
                      if (plVar9 != (longlong *)0x0) {
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          plStack_b0 = (longlong *)0x23c6368b9;
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar6 = *(longlong **)(lVar8 + 0x28);
                        plVar13 = (longlong *)plVar6[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar8 + 0x30);
                        *(undefined4 *)(plVar6 + 8) = 0xffffffff;
                        if (plVar13 != (longlong *)0x0) {
                          plVar6[2] = 0;
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            plStack_b0 = (longlong *)0x23c6368f2;
                            (**(code **)(plVar13[1] + 0x30))();
                          }
                        }
                        *plVar6 = *plVar6 + -1;
                        if (*plVar6 == 0) {
                          plStack_b0 = (longlong *)0x23c636902;
                          (**(code **)(plVar6[1] + 0x30))(plVar6);
                        }
                        plVar6[0xf] = 0;
                        pcVar15 = _Py_NoneStruct_exref;
                        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
LAB_23c636a73:
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          plStack_b0 = (longlong *)0x23c636a84;
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        *plVar1 = *plVar1 + -1;
                        if (*plVar1 != 0) {
                          return pcVar15;
                        }
                        plStack_b0 = (longlong *)0x23c636a96;
                        (**(code **)(plVar1[1] + 0x30))(plVar1);
                        return pcVar15;
                      }
                      goto LAB_23c636e50;
                    }
                  }
                  plVar7 = *(longlong **)(param_1 + 0x60);
                  pcVar15 = *(code **)(param_1 + 0x68);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    plStack_b0 = (longlong *)0x23c637011;
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  plVar6 = uStack_80;
                  *uStack_80 = *uStack_80 + -1;
                  uVar20 = 0x186;
                  plVar11 = DAT_23ed6a4f8;
                  plVar3 = uStack_80;
                  if (*uStack_80 == 0) {
                    plVar11 = uStack_80 + 1;
                    uStack_80 = (longlong *)CONCAT44(uStack_80._4_4_,0x186);
                    plStack_b0 = (longlong *)0x23c637035;
                    (**(code **)(*plVar11 + 0x30))(plVar6);
                    uVar20 = SUB84(uStack_80,0);
                    plVar11 = DAT_23ed6a4f8;
                    plVar3 = uStack_80;
                  }
                }
                goto joined_r0x00023c636af5;
              }
            }
            plVar7 = *(longlong **)(param_1 + 0x60);
            uVar20 = 0x184;
            plVar9 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar15 = *(code **)(param_1 + 0x68);
            plVar11 = DAT_23ed6a4f8;
            plVar3 = uStack_80;
            goto joined_r0x00023c636af5;
          }
        }
LAB_23c636de0:
        plVar7 = *(longlong **)(param_1 + 0x60);
        uVar20 = 0x17f;
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar15 = *(code **)(param_1 + 0x68);
        plVar11 = DAT_23ed6a4f8;
        plVar3 = uStack_80;
        goto joined_r0x00023c636af5;
      }
    }
  }
  plVar7 = *(longlong **)(param_1 + 0x60);
  uVar20 = 0x17d;
  plVar9 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  pcVar15 = *(code **)(param_1 + 0x68);
  plVar11 = DAT_23ed6a4f8;
  plVar3 = uStack_80;
joined_r0x00023c636af5:
  uStack_80._4_4_ = (undefined4)((ulonglong)plVar3 >> 0x20);
  DAT_23ed6a4f8 = plVar11;
  uStack_80 = plVar3;
  if (plVar9 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      uStack_80 = (longlong *)CONCAT44(uStack_80._4_4_,uVar20);
      plStack_b0 = (longlong *)0x23c636f01;
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar20 = SUB84(uStack_80,0);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar2 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar13;
    *plVar13 = *plVar13 + 1;
    lVar8 = *(longlong *)(pcVar2 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar10 = plVar11[-1];
    puVar17 = *(undefined8 **)(lVar8 + 8);
    *puVar17 = plVar11 + -2;
    plVar11[-2] = lVar8;
    plVar11[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar8 + 8) = plVar11 + -2;
    plVar6 = plVar11;
    plVar3 = uStack_80;
  }
  else {
    plVar6 = plVar9;
    if ((longlong *)plVar9[3] != plVar13) {
      if (plVar11 == (longlong *)0x0) {
        uStack_80 = (longlong *)CONCAT44(uStack_80._4_4_,uVar20);
        plStack_b0 = (longlong *)0x23c636e21;
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar20 = SUB84(uStack_80,0);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar2 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar13;
      *plVar13 = *plVar13 + 1;
      lVar8 = *(longlong *)(pcVar2 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
      lVar10 = plVar11[-1];
      puVar17 = *(undefined8 **)(lVar8 + 8);
      *puVar17 = plVar11 + -2;
      plVar11[-2] = lVar8;
      plVar11[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar17;
      lVar10 = *plVar9;
      *(longlong **)(lVar8 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      plVar6 = plVar11;
      plVar3 = uStack_80;
      if (lVar10 == 0) {
        plStack_b0 = (longlong *)0x23c636c8a;
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        plVar3 = uStack_80;
      }
    }
  }
  uStack_80 = plVar3;
  plStack_b0 = (longlong *)0x23c636bac;
  FUN_23e8bba40(plVar13,&DAT_23ec47929,plVar12,plVar1);
  if (_DAT_23ee29c60 == plVar13) {
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      plStack_b0 = (longlong *)0x23c636c70;
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    _DAT_23ee29c60 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar8 + 0x28);
  plVar9 = (longlong *)plVar13[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      plStack_b0 = (longlong *)0x23c636bf2;
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    plStack_b0 = (longlong *)0x23c636c02;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar13[0xf] = 0;
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    plStack_b0 = (longlong *)0x23c636c1b;
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    plStack_b0 = (longlong *)0x23c636c2d;
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  plStack_b0 = (longlong *)0x23c636c3e;
  FUN_23a33aa70(param_1,plVar7,pcVar15,plVar6);
  return (code *)0x0;
}
