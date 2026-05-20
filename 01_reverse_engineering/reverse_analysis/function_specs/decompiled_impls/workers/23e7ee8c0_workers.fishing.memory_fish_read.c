/* ===== 23e7ee8c0 workers.fishing.memory_fish_read:165 ===== */
/* ghidra_name=FUN_23e7ee8c0 entry=23e7ee8c0 size=2457 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7ee8c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar11 = _DAT_23eedeae8;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedeae8 == (longlong *)0x0) {
LAB_23e7ee8fa:
    _DAT_23eedeae8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeae0,DAT_23eedebc0,8);
  }
  else {
    lVar12 = *_DAT_23eedeae8;
    if (1 < lVar12) {
      *_DAT_23eedeae8 = lVar12 + -1;
      goto LAB_23e7ee8fa;
    }
    if (_DAT_23eedeae8[2] != 0) {
      *_DAT_23eedeae8 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e7ee8fa;
    }
  }
  plVar4 = _DAT_23eedeae8;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eedeae8 + 9;
  lVar2 = *(longlong *)(lVar12 + 8);
  _DAT_23eedeae8[0xf] = lVar2;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  lVar2 = DAT_23eeddba8;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar12 = *(longlong *)(lVar2 + 0x20);
  if (*(char *)(lVar12 + 10) == '\0') {
    plVar11 = (longlong *)FUN_23a37a020(lVar2,_DAT_23eedde38);
    if (plVar11 == (longlong *)0x0) goto LAB_23e7eed41;
    lVar12 = *plVar11;
LAB_23e7ef058:
    if (lVar12 == 0) goto LAB_23e7eed41;
  }
  else {
    iVar10 = *(int *)(lVar12 + 0xc);
    if (*(int *)(lVar12 + 0xc) == 0) {
      *(int *)(lVar12 + 0xc) = DAT_23ec15618;
      iVar10 = DAT_23ec15618;
      DAT_23ec15618 = DAT_23ec15618 + 1;
    }
    if (_DAT_23ec155ec != iVar10) {
      _DAT_23ec155ec = iVar10;
      _DAT_23eedead8 = FUN_23e8cbd60(lVar12,_DAT_23eedde38,*(undefined8 *)(_DAT_23eedde38 + 0x18));
    }
    if (-1 < _DAT_23eedead8) {
      lVar2 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
      if (*(longlong *)(lVar2 + 8 + _DAT_23eedead8 * 0x10) != 0) goto LAB_23e7ee9ea;
      _DAT_23eedead8 = FUN_23e8cbd60(lVar12,_DAT_23eedde38,*(undefined8 *)(_DAT_23eedde38 + 0x18));
      if (-1 < _DAT_23eedead8) {
        lVar12 = *(longlong *)(lVar2 + 8 + _DAT_23eedead8 * 0x10);
        goto LAB_23e7ef058;
      }
    }
LAB_23e7eed41:
    plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedde38);
    if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) {
      uVar14 = 0xa6;
      FUN_23e915740(param_1,&uStack_68,_DAT_23eedde38);
      plVar11 = plStack_58;
      uVar6 = uStack_68;
      uVar5 = uStack_60;
      plVar7 = DAT_23ed6a4f8;
      goto joined_r0x00023e7eee85;
    }
  }
LAB_23e7ee9ea:
  *(undefined4 *)(plVar4 + 5) = 0xa6;
  plVar11 = (longlong *)FUN_23e91a870(param_1);
  if (plVar11 != (longlong *)0x0) {
    cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde40,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (cVar9 != '\0') {
      lVar12 = FUN_23e8dd520();
      if (lVar12 == 0) {
        uVar14 = 0xa7;
        FUN_23e915740(param_1,&uStack_68,_DAT_23eedde48);
        plVar11 = plStack_58;
        uVar6 = uStack_68;
        uVar5 = uStack_60;
        plVar7 = DAT_23ed6a4f8;
        goto joined_r0x00023e7eee85;
      }
      *(undefined4 *)(plVar4 + 5) = 0xa7;
      plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar12,_DAT_23eedde50);
      if (plVar11 != (longlong *)0x0) {
        cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde58,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (cVar9 != '\0') {
          lVar12 = *(longlong *)(param_1 + 0x10);
          if (*(int *)(lVar12 + 0x1188) == 0) {
            plVar11 = (longlong *)FUN_23a33a530(PyList_Type_exref);
          }
          else {
            iVar10 = *(int *)(lVar12 + 0x1188) + -1;
            *(int *)(lVar12 + 0x1188) = iVar10;
            plVar11 = *(longlong **)(lVar12 + 0xf08 + (longlong)iVar10 * 8);
            *plVar11 = 1;
          }
          pcVar8 = _PyRuntime_exref;
          plVar11[2] = 0;
          plVar11[4] = 0;
          lVar12 = *(longlong *)(pcVar8 + 0x1f8);
          plVar11[3] = 0;
          lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
          lVar2 = plVar11[-1];
          puVar3 = *(undefined8 **)(lVar12 + 8);
          *puVar3 = plVar11 + -2;
          plVar11[-2] = lVar12;
          plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
          *(longlong **)(lVar12 + 8) = plVar11 + -2;
          cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde60,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (cVar9 == '\0') {
            uVar6 = *(undefined8 *)(param_1 + 0x60);
            uVar14 = 0xa8;
            plVar11 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar5 = *(undefined8 *)(param_1 + 0x68);
            plVar7 = DAT_23ed6a4f8;
          }
          else {
            lVar12 = FUN_23e8dd520();
            if (lVar12 == 0) {
              uVar14 = 0xa9;
              FUN_23e915740(param_1,&uStack_68,_DAT_23eedde48);
              plVar11 = plStack_58;
              uVar6 = uStack_68;
              uVar5 = uStack_60;
              plVar7 = DAT_23ed6a4f8;
            }
            else {
              *(undefined4 *)(plVar4 + 5) = 0xa9;
              plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar12,_DAT_23eedde68);
              if (plVar11 != (longlong *)0x0) {
                cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde70,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (cVar9 != '\0') {
                  lVar12 = FUN_23e8dd520();
                  if (lVar12 == 0) {
                    uVar14 = 0xaa;
                    FUN_23e915740(param_1,&uStack_68,_DAT_23eedde48);
                    plVar11 = plStack_58;
                    uVar6 = uStack_68;
                    uVar5 = uStack_60;
                    plVar7 = DAT_23ed6a4f8;
                    goto joined_r0x00023e7eee85;
                  }
                  *(undefined4 *)(plVar4 + 5) = 0xaa;
                  plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar12,_DAT_23eedde68);
                  if (plVar11 != (longlong *)0x0) {
                    cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde78,plVar11);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (cVar9 != '\0') {
                      lVar12 = FUN_23e8dd520();
                      if (lVar12 == 0) {
                        uVar14 = 0xab;
                        FUN_23e915740(param_1,&uStack_68,_DAT_23eedde48);
                        plVar11 = plStack_58;
                        uVar6 = uStack_68;
                        uVar5 = uStack_60;
                        plVar7 = DAT_23ed6a4f8;
                      }
                      else {
                        *(undefined4 *)(plVar4 + 5) = 0xab;
                        plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar12,_DAT_23eedde68);
                        if (plVar11 != (longlong *)0x0) {
                          cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde80,plVar11);
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          pcVar8 = _Py_NoneStruct_exref;
                          if (cVar9 != '\0') {
                            cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde88,_Py_NoneStruct_exref);
                            if (cVar9 == '\0') {
                              uVar6 = *(undefined8 *)(param_1 + 0x60);
                              uVar14 = 0xac;
                              plVar11 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar5 = *(undefined8 *)(param_1 + 0x68);
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              cVar9 = FUN_23e8d9ac0(plVar1,_DAT_23eedde90,_Py_FalseStruct_exref);
                              if (cVar9 != '\0') {
                                lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                plVar11 = *(longlong **)(lVar12 + 0x28);
                                plVar4 = (longlong *)plVar11[2];
                                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                     *(undefined8 *)(lVar12 + 0x30);
                                *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                                if (plVar4 != (longlong *)0x0) {
                                  plVar11[2] = 0;
                                  *plVar4 = *plVar4 + -1;
                                  if (*plVar4 == 0) {
                                    (**(code **)(plVar4[1] + 0x30))();
                                  }
                                }
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                                }
                                *(longlong *)pcVar8 = *(longlong *)pcVar8 + 1;
                                plVar11[0xf] = 0;
                                *plVar1 = *plVar1 + -1;
                                if (*plVar1 != 0) {
                                  return pcVar8;
                                }
                                (**(code **)(plVar1[1] + 0x30))(plVar1);
                                return pcVar8;
                              }
                              uVar6 = *(undefined8 *)(param_1 + 0x60);
                              uVar14 = 0xad;
                              plVar11 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar5 = *(undefined8 *)(param_1 + 0x68);
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e7eee85;
                          }
                        }
                        uVar6 = *(undefined8 *)(param_1 + 0x60);
                        uVar14 = 0xab;
                        plVar11 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar5 = *(undefined8 *)(param_1 + 0x68);
                        plVar7 = DAT_23ed6a4f8;
                      }
                      goto joined_r0x00023e7eee85;
                    }
                  }
                  uVar6 = *(undefined8 *)(param_1 + 0x60);
                  uVar14 = 0xaa;
                  plVar11 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar5 = *(undefined8 *)(param_1 + 0x68);
                  plVar7 = DAT_23ed6a4f8;
                  goto joined_r0x00023e7eee85;
                }
              }
              uVar6 = *(undefined8 *)(param_1 + 0x60);
              uVar14 = 0xa9;
              plVar11 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar5 = *(undefined8 *)(param_1 + 0x68);
              plVar7 = DAT_23ed6a4f8;
            }
          }
          goto joined_r0x00023e7eee85;
        }
      }
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = 0xa7;
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar5 = *(undefined8 *)(param_1 + 0x68);
      plVar7 = DAT_23ed6a4f8;
      goto joined_r0x00023e7eee85;
    }
  }
  plVar11 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0xa6;
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar7 = DAT_23ed6a4f8;
joined_r0x00023e7eee85:
  DAT_23ed6a4f8 = plVar7;
  if (plVar11 == (longlong *)0x0) {
    if (plVar7 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar7;
      *plVar7 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar7;
    }
    pcVar8 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar12 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar2 = plVar13[-1];
    puVar3 = *(undefined8 **)(lVar12 + 8);
    *puVar3 = plVar13 + -2;
    plVar13[-2] = lVar12;
    plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar12 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar11;
    if ((longlong *)plVar11[3] != plVar4) {
      if (plVar7 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar7;
        *plVar7 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar7;
      }
      pcVar8 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar12 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar2 = plVar13[-1];
      puVar3 = *(undefined8 **)(lVar12 + 8);
      *puVar3 = plVar13 + -2;
      plVar13[-2] = lVar12;
      plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar11;
      *(longlong **)(lVar12 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar11;
      if (lVar2 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eedeae8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eedeae8 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar12 + 0x28);
  plVar4 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar6,uVar5,plVar13);
  return (code *)0x0;
}
