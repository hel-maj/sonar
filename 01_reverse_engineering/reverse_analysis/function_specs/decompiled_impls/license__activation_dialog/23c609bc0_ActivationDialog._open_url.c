/* ===== 23c609bc0 license.activation_dialog:c1031 ===== */
/* ghidra_name=FUN_23c609bc0 entry=23c609bc0 size=2389 */

code * FUN_23c609bc0(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined4 uVar14;
  code *pcVar15;
  code *local_68;
  undefined8 uStack_60;
  longlong *local_58 [3];
  
  plVar9 = DAT_23ee29f78;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  local_58[0] = (longlong *)0x0;
  local_68 = (code *)0x0;
  uStack_60 = 0;
  if (DAT_23ee29f78 == (longlong *)0x0) {
LAB_23c609c1e:
    DAT_23ee29f78 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29f68,DAT_23ee29f70,0x20);
  }
  else {
    lVar12 = *DAT_23ee29f78;
    if (1 < lVar12) {
      *DAT_23ee29f78 = lVar12 + -1;
      goto LAB_23c609c1e;
    }
    if (DAT_23ee29f78[2] != 0) {
      *DAT_23ee29f78 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23c609c1e;
    }
  }
  plVar5 = DAT_23ee29f78;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23ee29f78 + 9;
  lVar4 = *(longlong *)(lVar12 + 8);
  DAT_23ee29f78[0xf] = lVar4;
  *(longlong **)(lVar12 + 8) = plVar9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  pcVar7 = _Py_NoneStruct_exref;
  lVar12 = *(longlong *)(*(longlong *)(param_2 + 0xd8) + 0x10);
  if (lVar12 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar12 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar12 = DAT_23ed6cd40 + 0x30;
    }
    uStack_60 = PyUnicode_FromFormat
                          ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                           ,lVar12);
    local_68 = *(code **)PyExc_NameError_exref;
    *(longlong *)local_68 = *(longlong *)local_68 + 1;
    local_58[0] = (longlong *)0x0;
    if (local_68 != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,&local_68,&uStack_60,local_58);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uStack_60);
    uVar14 = 0x26;
    plVar9 = local_58[0];
    plVar10 = DAT_23ed6a4f8;
    goto joined_r0x00023c60a203;
  }
  pcVar15 = (code *)0x0;
  if (pcVar1 != _Py_NoneStruct_exref) {
    pcVar15 = pcVar1;
  }
  plVar9 = (longlong *)FUN_23e9543b0(param_1,DAT_23ee29728,lVar12,pcVar15);
  if (plVar9 != (longlong *)0x0) {
    *(undefined4 *)(plVar5 + 5) = 0x26;
    plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,DAT_23ed6cdb0,plVar3);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      cVar8 = FUN_23e8d9ac0(pcVar1,DAT_23ee28f80,plVar2);
      if (cVar8 == '\0') {
        plVar9 = *(longlong **)(param_1 + 0x70);
        local_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0x27;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023c60a203;
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(pcVar1,DAT_23ee28f88);
      if (plVar11 == (longlong *)0x0) {
LAB_23c60a3a0:
        local_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = *(longlong **)(param_1 + 0x70);
        uVar14 = 0x2a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = DAT_23ed6a4f8;
        goto joined_r0x00023c60a203;
      }
      lVar12 = FUN_23ead7940();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,&local_68,DAT_23ee28f90);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
          uVar14 = 0x2a;
          plVar9 = local_58[0];
          plVar10 = DAT_23ed6a4f8;
          goto joined_r0x00023c60a203;
        }
LAB_23c60a338:
        uVar14 = 0x2a;
        plVar9 = local_58[0];
        plVar10 = DAT_23ed6a4f8;
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23ee28f98);
        if (plVar9 != (longlong *)0x0) {
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ee28fa0);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          if (plVar10 != (longlong *)0x0) {
            lVar12 = FUN_23ead7940();
            if (lVar12 == 0) {
              FUN_23e915740(param_1,&local_68,DAT_23ee28f90);
              *plVar11 = *plVar11 + -1;
              lVar12 = *plVar11;
            }
            else {
              plVar9 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23ee28f98);
              if (plVar9 != (longlong *)0x0) {
                plVar13 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23ee28fa8);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
                if (plVar13 != (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23e8c1360(plVar10);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (plVar9 != (longlong *)0x0) {
                    *(undefined4 *)(plVar5 + 5) = 0x2a;
                    plVar10 = (longlong *)FUN_23e914090(param_1,plVar11);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar10 != (longlong *)0x0) {
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      *(undefined4 *)(plVar5 + 5) = 0x2c;
                      plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23ee28fb0);
                      if (plVar9 != (longlong *)0x0) {
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar9 = *(longlong **)(lVar12 + 0x28);
                        plVar5 = (longlong *)plVar9[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar12 + 0x30);
                        *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                        if (plVar5 != (longlong *)0x0) {
                          plVar9[2] = 0;
                          *plVar5 = *plVar5 + -1;
                          if (*plVar5 == 0) {
                            (**(code **)(plVar5[1] + 0x30))();
                          }
                        }
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                        plVar9[0xf] = 0;
                        *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
                        if (*(longlong *)pcVar1 == 0) {
                          (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
                        }
                        *plVar2 = *plVar2 + -1;
                        if (*plVar2 == 0) {
                          (**(code **)(plVar2[1] + 0x30))(plVar2);
                        }
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 != 0) {
                          return pcVar7;
                        }
                        (**(code **)(plVar3[1] + 0x30))(plVar3);
                        return pcVar7;
                      }
                      local_68 = *(code **)(param_1 + 0x60);
                      uStack_60 = *(undefined8 *)(param_1 + 0x68);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar14 = 0x2c;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar10 = DAT_23ed6a4f8;
                      goto joined_r0x00023c60a203;
                    }
                    goto LAB_23c60a3a0;
                  }
                  goto LAB_23c60a350;
                }
              }
              local_68 = *(code **)(param_1 + 0x60);
              uStack_60 = *(undefined8 *)(param_1 + 0x68);
              local_58[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar11 = *plVar11 + -1;
              lVar12 = *plVar11;
            }
            if (lVar12 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
              uVar14 = 0x2a;
              plVar9 = local_58[0];
              plVar10 = DAT_23ed6a4f8;
              goto joined_r0x00023c60a203;
            }
            goto LAB_23c60a338;
          }
        }
LAB_23c60a350:
        local_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        local_58[0] = *(longlong **)(param_1 + 0x70);
        uVar14 = 0x2a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        plVar9 = local_58[0];
        plVar10 = DAT_23ed6a4f8;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
          uVar14 = 0x2a;
          plVar9 = local_58[0];
          plVar10 = DAT_23ed6a4f8;
        }
      }
      goto joined_r0x00023c60a203;
    }
  }
  local_68 = *(code **)(param_1 + 0x60);
  uStack_60 = *(undefined8 *)(param_1 + 0x68);
  plVar9 = *(longlong **)(param_1 + 0x70);
  uVar14 = 0x26;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
joined_r0x00023c60a203:
  DAT_23ed6a4f8 = plVar10;
  local_58[0] = plVar9;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar14;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar12 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar9 = plVar10;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))(local_58[0]);
    }
  }
  else if ((longlong *)plVar9[3] != plVar5) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar14;
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar12 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    plVar9 = plVar10;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))();
    }
  }
  local_58[0] = plVar9;
  FUN_23e8bba40(plVar5,&DAT_23ec479c4,pcVar1,plVar2,plVar3,*(undefined8 *)(param_2 + 0xd8));
  if (DAT_23ee29f78 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    DAT_23ee29f78 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar12 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
  if (*(longlong *)pcVar1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,local_68,uStack_60,local_58[0]);
  return (code *)0x0;
}
