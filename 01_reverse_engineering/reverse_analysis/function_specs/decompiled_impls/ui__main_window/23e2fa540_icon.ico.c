/* ===== 23e2fa540 ui.main_window:c1105 ===== */
/* ghidra_name=FUN_23e2fa540 entry=23e2fa540 size=9374 */

/* WARNING: Type propagation algorithm not settling */

code * FUN_23e2fa540(longlong param_1,longlong param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  ulonglong uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined8 *puVar18;
  longlong lVar19;
  longlong *local_88;
  longlong lStack_80;
  code *local_78;
  undefined8 uStack_70;
  longlong *local_68 [5];
  
  plVar8 = DAT_23eeaff90;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_68[0] = (longlong *)0x0;
  local_78 = (code *)0x0;
  uStack_70 = 0;
  if (DAT_23eeaff90 == (longlong *)0x0) {
LAB_23e2fa59e:
    DAT_23eeaff90 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeac6a0,DAT_23eeac668,0x18);
  }
  else {
    lVar11 = *DAT_23eeaff90;
    if (1 < lVar11) {
      *DAT_23eeaff90 = lVar11 + -1;
      goto LAB_23e2fa59e;
    }
    if (DAT_23eeaff90[2] != 0) {
      *DAT_23eeaff90 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e2fa59e;
    }
  }
  plVar3 = DAT_23eeaff90;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eeaff90 + 9;
  lVar12 = *(longlong *)(lVar11 + 8);
  DAT_23eeaff90[0xf] = lVar12;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  lVar11 = *(longlong *)(param_2 + 0xd8);
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar11 = *(longlong *)(lVar11 + 0x10);
  if (lVar11 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar11 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar11 = DAT_23ed6cd40 + 0x30;
    }
    uStack_70 = PyUnicode_FromFormat
                          ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                           ,lVar11);
    local_78 = *(code **)PyExc_NameError_exref;
    *(longlong *)local_78 = *(longlong *)local_78 + 1;
    local_68[0] = (longlong *)0x0;
    if (local_78 != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,&local_78,&uStack_70,local_68);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uStack_70);
    uVar16 = 0x25;
    plVar8 = local_68[0];
    plVar9 = DAT_23ed6a4f8;
    goto joined_r0x00023e2fb923;
  }
  plVar8 = (longlong *)FUN_23e954510(param_1,DAT_23eeac660,lVar11,plVar1);
  if (plVar8 != (longlong *)0x0) {
    *(undefined4 *)(plVar3 + 5) = 0x25;
    plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23ed6cdb0,plVar2);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eeac6e0,DAT_23ed6cd08);
      if (cVar6 == '\0') {
        plVar8 = *(longlong **)(param_1 + 0x70);
        local_78 = *(code **)(param_1 + 0x60);
        uStack_70 = *(undefined8 *)(param_1 + 0x68);
        uVar16 = 0x26;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e2fb923;
      }
      lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
      if (*(char *)(lVar11 + 10) == '\0') {
        plVar8 = (longlong *)FUN_23a37a020(DAT_23eeac660,DAT_23eeac6e8);
        if (plVar8 == (longlong *)0x0) goto LAB_23e2fb8a9;
        lVar11 = *plVar8;
LAB_23e2fbd58:
        if (lVar11 == 0) goto LAB_23e2fb8a9;
      }
      else {
        iVar7 = *(int *)(lVar11 + 0xc);
        if (*(int *)(lVar11 + 0xc) == 0) {
          *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
          iVar7 = DAT_23ec14e10;
          DAT_23ec14e10 = DAT_23ec14e10 + 1;
        }
        if (DAT_23ec14de4 != iVar7) {
          DAT_23ec14de4 = iVar7;
          DAT_23eeaff30 = FUN_23e8cbd60(lVar11,DAT_23eeac6e8,*(undefined8 *)(DAT_23eeac6e8 + 0x18));
        }
        if (-1 < DAT_23eeaff30) {
          lVar12 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
          if (*(longlong *)(lVar12 + 8 + DAT_23eeaff30 * 0x10) != 0) goto LAB_23e2fa727;
          DAT_23eeaff30 = FUN_23e8cbd60(lVar11,DAT_23eeac6e8,*(undefined8 *)(DAT_23eeac6e8 + 0x18));
          if (-1 < DAT_23eeaff30) {
            lVar11 = *(longlong *)(lVar12 + 8 + DAT_23eeaff30 * 0x10);
            goto LAB_23e2fbd58;
          }
        }
LAB_23e2fb8a9:
        plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac6e8);
        if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
          FUN_23e915740(param_1,&local_78,DAT_23eeac6e8);
          uVar16 = 0x29;
          plVar8 = local_68[0];
          plVar9 = DAT_23ed6a4f8;
          goto joined_r0x00023e2fb923;
        }
      }
LAB_23e2fa727:
      *(undefined4 *)(plVar3 + 5) = 0x29;
      plVar8 = (longlong *)FUN_23e91a870(param_1);
      if (plVar8 != (longlong *)0x0) {
        cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eeac6f0,plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (cVar6 != '\0') {
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac6f0);
          if (plVar8 != (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eeac6f8);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (plVar10 != (longlong *)0x0) {
              lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
              if (*(char *)(lVar11 + 10) != '\0') {
                iVar7 = *(int *)(lVar11 + 0xc);
                if (*(int *)(lVar11 + 0xc) == 0) {
                  *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                  iVar7 = DAT_23ec14e10;
                  DAT_23ec14e10 = DAT_23ec14e10 + 1;
                }
                if (DAT_23ec14de8 != iVar7) {
                  DAT_23ec14de8 = iVar7;
                  DAT_23eeaff38 =
                       FUN_23e8cbd60(lVar11,DAT_23eeac700,*(undefined8 *)(DAT_23eeac700 + 0x18));
                }
                if (-1 < DAT_23eeaff38) {
                  lVar12 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
                  lVar19 = *(longlong *)(lVar12 + 8 + DAT_23eeaff38 * 0x10);
                  if (lVar19 != 0) goto LAB_23e2fa81e;
                  DAT_23eeaff38 =
                       FUN_23e8cbd60(lVar11,DAT_23eeac700,*(undefined8 *)(DAT_23eeac700 + 0x18));
                  if (-1 < DAT_23eeaff38) {
                    lVar19 = *(longlong *)(lVar12 + 8 + DAT_23eeaff38 * 0x10);
                    goto LAB_23e2fbb5c;
                  }
                }
LAB_23e2fbb70:
                plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac700);
                lVar11 = DAT_23eeac700;
                if ((plVar8 != (longlong *)0x0) && (lVar19 = *plVar8, lVar19 != 0))
                goto LAB_23e2fa81e;
LAB_23e2fbba3:
                FUN_23e915740(param_1,&local_78,lVar11);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                  uVar16 = 0x2a;
                  plVar8 = local_68[0];
                  plVar9 = DAT_23ed6a4f8;
                }
                else {
                  uVar16 = 0x2a;
                  plVar8 = local_68[0];
                  plVar9 = DAT_23ed6a4f8;
                }
                goto joined_r0x00023e2fb923;
              }
              plVar8 = (longlong *)FUN_23a37a020(DAT_23eeac660,DAT_23eeac700);
              if (plVar8 == (longlong *)0x0) goto LAB_23e2fbb70;
              lVar19 = *plVar8;
LAB_23e2fbb5c:
              if (lVar19 == 0) goto LAB_23e2fbb70;
LAB_23e2fa81e:
              lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
              if (*(char *)(lVar11 + 10) == '\0') {
                plVar8 = (longlong *)FUN_23a37a020(DAT_23eeac660,DAT_23eeac708);
                if (plVar8 == (longlong *)0x0) goto LAB_23e2fbc30;
                lVar11 = *plVar8;
LAB_23e2fbc1e:
                if (lVar11 == 0) goto LAB_23e2fbc30;
              }
              else {
                iVar7 = *(int *)(lVar11 + 0xc);
                if (*(int *)(lVar11 + 0xc) == 0) {
                  *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                  iVar7 = DAT_23ec14e10;
                  DAT_23ec14e10 = DAT_23ec14e10 + 1;
                }
                if (DAT_23ec14dec != iVar7) {
                  DAT_23ec14dec = iVar7;
                  DAT_23eeaff40 =
                       FUN_23e8cbd60(lVar11,DAT_23eeac708,*(undefined8 *)(DAT_23eeac708 + 0x18));
                }
                if (-1 < DAT_23eeaff40) {
                  lVar12 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
                  if (*(longlong *)(lVar12 + 8 + DAT_23eeaff40 * 0x10) != 0) goto LAB_23e2fa88b;
                  DAT_23eeaff40 =
                       FUN_23e8cbd60(lVar11,DAT_23eeac708,*(undefined8 *)(DAT_23eeac708 + 0x18));
                  if (-1 < DAT_23eeaff40) {
                    lVar11 = *(longlong *)(lVar12 + 8 + DAT_23eeaff40 * 0x10);
                    goto LAB_23e2fbc1e;
                  }
                }
LAB_23e2fbc30:
                plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac708);
                lVar11 = DAT_23eeac708;
                if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) goto LAB_23e2fbba3;
              }
LAB_23e2fa88b:
              *(undefined4 *)(plVar3 + 5) = 0x2a;
              plVar8 = (longlong *)FUN_23e914090(param_1,lVar19);
              if (plVar8 == (longlong *)0x0) {
                local_78 = *(code **)(param_1 + 0x60);
                uStack_70 = *(undefined8 *)(param_1 + 0x68);
                local_68[0] = *(longlong **)(param_1 + 0x70);
                uVar16 = 0x2a;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = *plVar10 + -1;
                lVar11 = *plVar10;
joined_r0x00023e2fbe2c:
                plVar8 = local_68[0];
                plVar9 = DAT_23ed6a4f8;
                if (lVar11 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                  plVar8 = local_68[0];
                  plVar9 = DAT_23ed6a4f8;
                }
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x2a;
                plVar9 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (plVar9 == (longlong *)0x0) goto LAB_23e2fba30;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac6f0);
                if (plVar8 != (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eeac710);
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (plVar9 != (longlong *)0x0) {
                    lVar11 = FUN_23e8f5700();
                    if (lVar11 == 0) {
                      FUN_23e915740(param_1,&local_78,DAT_23eeac718);
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      uVar16 = 0x2b;
                      plVar8 = local_68[0];
                      plVar9 = DAT_23ed6a4f8;
                      goto joined_r0x00023e2fb923;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x2b;
                    plVar8 = (longlong *)FUN_23e914090(param_1,plVar9,lVar11);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar8 == (longlong *)0x0) goto LAB_23e2fbd70;
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac6f0);
                    if (plVar8 != (longlong *)0x0) {
                      plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eeac720);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (plVar9 != (longlong *)0x0) {
                        lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
                        if (*(char *)(lVar11 + 10) != '\0') {
                          iVar7 = *(int *)(lVar11 + 0xc);
                          if (*(int *)(lVar11 + 0xc) == 0) {
                            *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                            iVar7 = DAT_23ec14e10;
                            DAT_23ec14e10 = DAT_23ec14e10 + 1;
                          }
                          if (DAT_23ec14df0 != iVar7) {
                            DAT_23ec14df0 = iVar7;
                            DAT_23eeaff48 =
                                 FUN_23e8cbd60(lVar11,DAT_23eeac728,
                                               *(undefined8 *)(DAT_23eeac728 + 0x18));
                          }
                          if (-1 < DAT_23eeaff48) {
                            lVar12 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
                            plVar8 = *(longlong **)(lVar12 + 8 + DAT_23eeaff48 * 0x10);
                            if (plVar8 != (longlong *)0x0) goto LAB_23e2faa4b;
                            DAT_23eeaff48 =
                                 FUN_23e8cbd60(lVar11,DAT_23eeac728,
                                               *(undefined8 *)(DAT_23eeac728 + 0x18));
                            if (-1 < DAT_23eeaff48) {
                              plVar8 = *(longlong **)(lVar12 + 8 + DAT_23eeaff48 * 0x10);
                              goto LAB_23e2fbcd3;
                            }
                          }
LAB_23e2fbce0:
                          puVar18 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac728);
                          lVar11 = DAT_23eeac728;
                          if ((puVar18 != (undefined8 *)0x0) &&
                             (plVar8 = (longlong *)*puVar18, plVar8 != (longlong *)0x0))
                          goto LAB_23e2faa4b;
LAB_23e2fbd13:
                          FUN_23e915740(param_1,&local_78,lVar11);
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          uVar16 = 0x2c;
                          plVar8 = local_68[0];
                          plVar9 = DAT_23ed6a4f8;
                          goto joined_r0x00023e2fb923;
                        }
                        puVar18 = (undefined8 *)FUN_23a37a020(DAT_23eeac660,DAT_23eeac728);
                        if (puVar18 == (undefined8 *)0x0) goto LAB_23e2fbce0;
                        plVar8 = (longlong *)*puVar18;
LAB_23e2fbcd3:
                        if (plVar8 == (longlong *)0x0) goto LAB_23e2fbce0;
LAB_23e2faa4b:
                        lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
                        if (*(char *)(lVar11 + 10) == '\0') {
                          plVar10 = (longlong *)FUN_23a37a020(DAT_23eeac660,DAT_23eeac730);
                          if (plVar10 == (longlong *)0x0) goto LAB_23e2fbf00;
                          lVar12 = *plVar10;
LAB_23e2fbef5:
                          if (lVar12 == 0) goto LAB_23e2fbf00;
                        }
                        else {
                          iVar7 = *(int *)(lVar11 + 0xc);
                          if (*(int *)(lVar11 + 0xc) == 0) {
                            *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                            iVar7 = DAT_23ec14e10;
                            DAT_23ec14e10 = DAT_23ec14e10 + 1;
                          }
                          if (DAT_23ec14df4 != iVar7) {
                            DAT_23ec14df4 = iVar7;
                            DAT_23eeaff50 =
                                 FUN_23e8cbd60(lVar11,DAT_23eeac730,
                                               *(undefined8 *)(DAT_23eeac730 + 0x18));
                          }
                          if (-1 < DAT_23eeaff50) {
                            lVar19 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
                            lVar12 = *(longlong *)(lVar19 + 8 + DAT_23eeaff50 * 0x10);
                            if (lVar12 != 0) goto LAB_23e2faabc;
                            DAT_23eeaff50 =
                                 FUN_23e8cbd60(lVar11,DAT_23eeac730,
                                               *(undefined8 *)(DAT_23eeac730 + 0x18));
                            if (-1 < DAT_23eeaff50) {
                              lVar12 = *(longlong *)(lVar19 + 8 + DAT_23eeaff50 * 0x10);
                              goto LAB_23e2fbef5;
                            }
                          }
LAB_23e2fbf00:
                          plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac730);
                          lVar11 = DAT_23eeac730;
                          if ((plVar10 == (longlong *)0x0) || (lVar12 = *plVar10, lVar12 == 0))
                          goto LAB_23e2fbd13;
                        }
LAB_23e2faabc:
                        *(undefined4 *)(plVar3 + 5) = 0x2c;
                        local_88 = plVar8;
                        lStack_80 = lVar12;
                        plVar8 = (longlong *)FUN_23e94ed00(param_1,plVar9,&local_88);
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        if (plVar8 == (longlong *)0x0) goto LAB_23e2fbe50;
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac738);
                        if (plVar10 == (longlong *)0x0) {
LAB_23e2fc0d1:
                          local_78 = *(code **)(param_1 + 0x60);
                          uStack_70 = *(undefined8 *)(param_1 + 0x68);
                          plVar8 = *(longlong **)(param_1 + 0x70);
                          uVar16 = 0x2d;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar9 = DAT_23ed6a4f8;
                          goto joined_r0x00023e2fb923;
                        }
                        plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac6f0);
                        if (plVar8 == (longlong *)0x0) {
                          local_78 = *(code **)(param_1 + 0x60);
                          uStack_70 = *(undefined8 *)(param_1 + 0x68);
                          local_68[0] = *(longlong **)(param_1 + 0x70);
                          uVar16 = 0x2d;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar10 = *plVar10 + -1;
                          lVar11 = *plVar10;
                          goto joined_r0x00023e2fbe2c;
                        }
                        *(undefined4 *)(plVar3 + 5) = 0x2d;
                        plVar9 = (longlong *)FUN_23e914090(param_1,plVar10,plVar8);
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        if (plVar9 == (longlong *)0x0) goto LAB_23e2fc0d1;
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac740);
                        plVar8 = DAT_23eeac748;
                        if (plVar9 == (longlong *)0x0) {
LAB_23e2fc20c:
                          local_78 = *(code **)(param_1 + 0x60);
                          uStack_70 = *(undefined8 *)(param_1 + 0x68);
                          plVar8 = *(longlong **)(param_1 + 0x70);
                          uVar16 = 0x30;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar9 = DAT_23ed6a4f8;
                          goto joined_r0x00023e2fb923;
                        }
                        lVar11 = *(longlong *)(param_1 + 0x10);
                        plVar10 = *(longlong **)(lVar11 + 0xe78);
                        if (plVar10 == (longlong *)0x0) {
                          plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,0xd);
                        }
                        else {
                          lVar12 = plVar10[3];
                          *(int *)(lVar11 + 0xee8) = *(int *)(lVar11 + 0xee8) + -1;
                          *(longlong *)(lVar11 + 0xe78) = lVar12;
                          *plVar10 = 1;
                        }
                        plVar10[3] = 0;
                        plVar10[0xf] = 0;
                        puVar18 = (undefined8 *)((ulonglong)(plVar10 + 4) & 0xfffffffffffffff8);
                        for (uVar15 = (ulonglong)
                                      (((int)plVar10 -
                                       (int)(undefined8 *)
                                            ((ulonglong)(plVar10 + 4) & 0xfffffffffffffff8)) + 0x80U
                                      >> 3); uVar15 != 0; uVar15 = uVar15 - 1) {
                          *puVar18 = 0;
                          puVar18 = puVar18 + 1;
                        }
                        lVar11 = *(longlong *)
                                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                  0x2e8);
                        lVar12 = plVar10[-1];
                        puVar18 = *(undefined8 **)(lVar11 + 8);
                        *puVar18 = plVar10 + -2;
                        plVar10[-2] = lVar11;
                        plVar10[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar18;
                        *(longlong **)(lVar11 + 8) = plVar10 + -2;
                        lVar12 = DAT_23eeac660;
                        *plVar8 = *plVar8 + 1;
                        lVar11 = *(longlong *)(lVar12 + 0x20);
                        plVar10[3] = (longlong)plVar8;
                        if (*(char *)(lVar11 + 10) == '\0') {
                          puVar18 = (undefined8 *)FUN_23a37a020(lVar12,DAT_23eeac750);
                          if (puVar18 == (undefined8 *)0x0) goto LAB_23e2fc055;
                          plVar8 = (longlong *)*puVar18;
LAB_23e2fc04c:
                          if (plVar8 == (longlong *)0x0) goto LAB_23e2fc055;
LAB_23e2face1:
                          lVar11 = DAT_23ed6cd28;
                          puVar18 = &DAT_23ed6a4c0;
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar14 != (longlong *)0x0) {
                              *plVar14 = *plVar14 + 1;
                              DAT_23ed6a4c0 = plVar14;
                              goto LAB_23e2facfe;
                            }
LAB_23e2fc4cb:
                            PyErr_PrintEx(0,0);
                            iVar7 = Py_Exit(1);
LAB_23e2fc4de:
                            DAT_23ec14e08 = iVar7;
                            DAT_23eeaff78 =
                                 FUN_23e8cbd60(puVar18,DAT_23eeac798,
                                               *(undefined8 *)(DAT_23eeac798 + 0x18));
LAB_23e2fb0bc:
                            if (DAT_23eeaff78 < 0) {
LAB_23e2fc55b:
                              plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac798);
                              if ((plVar8 == (longlong *)0x0) || (lVar11 = *plVar8, lVar11 == 0)) {
                                FUN_23e915740(param_1,&local_78,DAT_23eeac798);
                                uVar16 = 0x36;
                                plVar8 = local_68[0];
                                plVar9 = DAT_23ed6a4f8;
                                goto joined_r0x00023e2fb923;
                              }
                            }
                            else {
                              lVar12 = 1L << (*(byte *)((longlong)puVar18 + 9) & 0x3f);
                              lVar11 = *(longlong *)
                                        ((longlong)puVar18 + DAT_23eeaff78 * 0x10 + lVar12 + 0x28);
                              if (lVar11 == 0) {
                                DAT_23eeaff78 =
                                     FUN_23e8cbd60(puVar18,DAT_23eeac798,
                                                   *(undefined8 *)(DAT_23eeac798 + 0x18));
                                if (-1 < DAT_23eeaff78) {
                                  lVar11 = *(longlong *)
                                            ((longlong)puVar18 +
                                            DAT_23eeaff78 * 0x10 + lVar12 + 0x28);
LAB_23e2fc552:
                                  if (lVar11 != 0) goto LAB_23e2fb0e8;
                                }
                                goto LAB_23e2fc55b;
                              }
                            }
LAB_23e2fb0e8:
                            lStack_80 = DAT_23eeac7a0;
                            *(undefined4 *)(plVar3 + 5) = 0x36;
                            local_88 = plVar1;
                            plVar8 = (longlong *)FUN_23e94ed00(param_1,lVar11,&local_88);
                            if (plVar8 != (longlong *)0x0) {
                              cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eeac7a8,plVar8);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              if (cVar6 != '\0') {
                                plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac7a8);
                                if (plVar8 != (longlong *)0x0) {
                                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eeac7b0);
                                  *plVar8 = *plVar8 + -1;
                                  if (*plVar8 == 0) {
                                    FUN_23a334bc0(plVar8);
                                  }
                                  if (plVar9 != (longlong *)0x0) {
                                    lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
                                    if (*(char *)(lVar11 + 10) == '\0') {
                                      plVar8 = (longlong *)
                                               FUN_23a37a020(DAT_23eeac660,DAT_23eeac7b8);
                                      if (plVar8 == (longlong *)0x0) goto LAB_23e2fc709;
                                      lVar11 = *plVar8;
LAB_23e2fc700:
                                      if (lVar11 == 0) goto LAB_23e2fc709;
                                    }
                                    else {
                                      iVar7 = *(int *)(lVar11 + 0xc);
                                      if (*(int *)(lVar11 + 0xc) == 0) {
                                        *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                                        iVar7 = DAT_23ec14e10;
                                        DAT_23ec14e10 = DAT_23ec14e10 + 1;
                                      }
                                      if (DAT_23ec14e0c != iVar7) {
                                        DAT_23ec14e0c = iVar7;
                                        DAT_23eeaff80 =
                                             FUN_23e8cbd60(lVar11,DAT_23eeac7b8,
                                                           *(undefined8 *)(DAT_23eeac7b8 + 0x18));
                                      }
                                      if (-1 < DAT_23eeaff80) {
                                        lVar12 = lVar11 + 0x20 +
                                                 (1L << (*(byte *)(lVar11 + 9) & 0x3f));
                                        if (*(longlong *)(lVar12 + 8 + DAT_23eeaff80 * 0x10) != 0)
                                        goto LAB_23e2fb21a;
                                        DAT_23eeaff80 =
                                             FUN_23e8cbd60(lVar11,DAT_23eeac7b8,
                                                           *(undefined8 *)(DAT_23eeac7b8 + 0x18));
                                        if (-1 < DAT_23eeaff80) {
                                          lVar11 = *(longlong *)(lVar12 + 8 + DAT_23eeaff80 * 0x10);
                                          goto LAB_23e2fc700;
                                        }
                                      }
LAB_23e2fc709:
                                      plVar8 = (longlong *)
                                               FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac7b8);
                                      if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
                                        FUN_23e915740(param_1,&local_78,DAT_23eeac7b8);
                                        *plVar9 = *plVar9 + -1;
                                        if (*plVar9 == 0) {
                                          FUN_23a334bc0(plVar9);
                                        }
                                        uVar16 = 0x37;
                                        plVar8 = local_68[0];
                                        plVar9 = DAT_23ed6a4f8;
                                        goto joined_r0x00023e2fb923;
                                      }
                                    }
LAB_23e2fb21a:
                                    *(undefined4 *)(plVar3 + 5) = 0x37;
                                    plVar8 = (longlong *)FUN_23e914090(param_1,plVar9);
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      FUN_23a334bc0(plVar9);
                                    }
                                    if (plVar8 != (longlong *)0x0) {
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0(plVar8);
                                      }
                                      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac7a8);
                                      lVar11 = DAT_23eeac7c8;
                                      uVar4 = DAT_23eeac7c0;
                                      if (plVar8 != (longlong *)0x0) {
                                        *(undefined4 *)(plVar3 + 5) = 0x38;
                                        plVar9 = (longlong *)
                                                 FUN_23e915840(param_1,plVar8,uVar4,
                                                               *(undefined8 *)(lVar11 + 0x18));
                                        *plVar8 = *plVar8 + -1;
                                        if (*plVar8 == 0) {
                                          FUN_23a334bc0(plVar8);
                                        }
                                        if (plVar9 != (longlong *)0x0) {
                                          *plVar9 = *plVar9 + -1;
                                          if (*plVar9 == 0) {
                                            FUN_23a334bc0(plVar9);
                                          }
                                          plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeac7a8);
                                          uVar4 = DAT_23eeac7d0;
                                          if (plVar8 != (longlong *)0x0) {
                                            *(undefined4 *)(plVar3 + 5) = 0x39;
                                            plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,uVar4)
                                            ;
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              FUN_23a334bc0(plVar8);
                                            }
                                            if (plVar9 != (longlong *)0x0) {
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0(plVar9);
                                              }
                                              plVar8 = (longlong *)
                                                       FUN_23e8bc2f0(plVar1,DAT_23eeac7a8);
                                              if (plVar8 != (longlong *)0x0) {
                                                plVar10 = (longlong *)
                                                          FUN_23e8bc2f0(plVar8,DAT_23eeac7e0);
                                                *plVar8 = *plVar8 + -1;
                                                if (*plVar8 == 0) {
                                                  FUN_23a334bc0(plVar8);
                                                }
                                                if (plVar10 != (longlong *)0x0) {
                                                  lVar11 = *(longlong *)(DAT_23eeac660 + 0x20);
                                                  if (*(char *)(lVar11 + 10) == '\0') {
                                                    plVar8 = (longlong *)
                                                             FUN_23a37a020(DAT_23eeac660,
                                                                           DAT_23eeac7e8);
                                                    if (plVar8 == (longlong *)0x0)
                                                    goto LAB_23e2fc934;
                                                    lVar12 = *plVar8;
LAB_23e2fc92b:
                                                    if (lVar12 == 0) goto LAB_23e2fc934;
                                                  }
                                                  else {
                                                    iVar7 = *(int *)(lVar11 + 0xc);
                                                    if (*(int *)(lVar11 + 0xc) == 0) {
                                                      *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                                                      iVar7 = DAT_23ec14e10;
                                                      DAT_23ec14e10 = DAT_23ec14e10 + 1;
                                                    }
                                                    if (DAT_23ec14e14 != iVar7) {
                                                      DAT_23ec14e14 = iVar7;
                                                      DAT_23eeaff88 =
                                                           FUN_23e8cbd60(lVar11,DAT_23eeac7e8,
                                                                         *(undefined8 *)
                                                                          (DAT_23eeac7e8 + 0x18));
                                                    }
                                                    if (-1 < DAT_23eeaff88) {
                                                      lVar19 = lVar11 + 0x20 +
                                                               (1L << (*(byte *)(lVar11 + 9) & 0x3f)
                                                               );
                                                      lVar12 = *(longlong *)
                                                                (lVar19 + 8 + DAT_23eeaff88 * 0x10);
                                                      if (lVar12 != 0) goto LAB_23e2fb3f9;
                                                      DAT_23eeaff88 =
                                                           FUN_23e8cbd60(lVar11,DAT_23eeac7e8,
                                                                         *(undefined8 *)
                                                                          (DAT_23eeac7e8 + 0x18));
                                                      if (-1 < DAT_23eeaff88) {
                                                        lVar12 = *(longlong *)
                                                                  (lVar19 + 8 + DAT_23eeaff88 * 0x10
                                                                  );
                                                        goto LAB_23e2fc92b;
                                                      }
                                                    }
LAB_23e2fc934:
                                                    plVar8 = (longlong *)
                                                             FUN_23a37a020(DAT_23ed6ccc0,
                                                                           DAT_23eeac7e8);
                                                    if ((plVar8 == (longlong *)0x0) ||
                                                       (lVar12 = *plVar8, lVar12 == 0)) {
                                                      FUN_23e915740(param_1,&local_78,DAT_23eeac7e8)
                                                      ;
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      uVar16 = 0x3a;
                                                      plVar8 = local_68[0];
                                                      plVar9 = DAT_23ed6a4f8;
                                                      goto joined_r0x00023e2fb923;
                                                    }
                                                  }
LAB_23e2fb3f9:
                                                  plVar8 = (longlong *)
                                                           FUN_23e8bc2f0(lVar12,DAT_23eeac7f0);
                                                  if (plVar8 == (longlong *)0x0) {
LAB_23e2fc8b7:
                                                    local_78 = *(code **)(param_1 + 0x60);
                                                    uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                                    local_68[0] = *(longlong **)(param_1 + 0x70);
                                                    uVar16 = 0x3a;
                                                    uVar17 = 0x3a;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar10 = *plVar10 + -1;
                                                    lVar11 = *plVar10;
                                                  }
                                                  else {
                                                    plVar9 = (longlong *)
                                                             FUN_23e8bc2f0(plVar8,DAT_23eeac7f8);
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar9 == (longlong *)0x0)
                                                    goto LAB_23e2fc8b7;
                                                    *(undefined4 *)(plVar3 + 5) = 0x3a;
                                                    plVar8 = (longlong *)
                                                             FUN_23e914090(param_1,plVar10);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    if (plVar8 == (longlong *)0x0)
                                                    goto LAB_23e2fc85f;
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    plVar8 = (longlong *)
                                                             FUN_23e8bc2f0(plVar1,DAT_23eeac7a8);
                                                    lVar11 = DAT_23eeac808;
                                                    uVar4 = DAT_23eeac800;
                                                    if (plVar8 == (longlong *)0x0) {
LAB_23e2fc9d4:
                                                      local_78 = *(code **)(param_1 + 0x60);
                                                      uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      uVar16 = 0x3b;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar9 = DAT_23ed6a4f8;
                                                      goto joined_r0x00023e2fb923;
                                                    }
                                                    *(undefined4 *)(plVar3 + 5) = 0x3b;
                                                    plVar9 = (longlong *)
                                                             FUN_23e915840(param_1,plVar8,uVar4,
                                                                           *(undefined8 *)
                                                                            (lVar11 + 0x18));
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar9 == (longlong *)0x0)
                                                    goto LAB_23e2fc9d4;
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1);
                                                    if (plVar8 == (longlong *)0x0) {
LAB_23e2fc803:
                                                      local_78 = *(code **)(param_1 + 0x60);
                                                      uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar9 = DAT_23ed6a4f8;
                                                      uVar16 = 0x3c;
                                                      goto joined_r0x00023e2fb923;
                                                    }
                                                    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8);
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0(plVar8);
                                                    }
                                                    if (plVar9 == (longlong *)0x0)
                                                    goto LAB_23e2fc803;
                                                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar9);
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    if (plVar10 == (longlong *)0x0)
                                                    goto LAB_23e2fc803;
                                                    plVar8 = (longlong *)
                                                             FUN_23e8bc2f0(plVar1,DAT_23eeac820);
                                                    if (plVar8 != (longlong *)0x0) {
                                                      *(undefined4 *)(plVar3 + 5) = 0x3c;
                                                      plVar9 = (longlong *)
                                                               FUN_23e914090(param_1,plVar10,plVar8)
                                                      ;
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0(plVar8);
                                                      }
                                                      if (plVar9 != (longlong *)0x0) {
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0(plVar9);
                                                        }
                                                        plVar8 = (longlong *)
                                                                 FUN_23e8bc2f0(plVar1,DAT_23eeac7a8)
                                                        ;
                                                        if (plVar8 != (longlong *)0x0) {
                                                          *(undefined4 *)(plVar3 + 5) = 0x3d;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e91bfe0(param_1,plVar8,
                                                                                 DAT_23eeac828);
                                                          *plVar8 = *plVar8 + -1;
                                                          if (*plVar8 == 0) {
                                                            FUN_23a334bc0(plVar8);
                                                          }
                                                          if (plVar9 != (longlong *)0x0) {
                                                            *plVar9 = *plVar9 + -1;
                                                            if (*plVar9 == 0) {
                                                              FUN_23a334bc0(plVar9);
                                                            }
                                                            FUN_23ebf6b20(*(undefined8 *)
                                                                           (param_1 + 0x38));
                                                            pcVar5 = _Py_NoneStruct_exref;
                                                            *(longlong *)_Py_NoneStruct_exref =
                                                                 *(longlong *)_Py_NoneStruct_exref +
                                                                 1;
                                                            *plVar1 = *plVar1 + -1;
                                                            if (*plVar1 == 0) {
                                                              FUN_23a334bc0(plVar1);
                                                            }
                                                            *plVar2 = *plVar2 + -1;
                                                            if (*plVar2 != 0) {
                                                              return pcVar5;
                                                            }
                                                            FUN_23a334bc0(plVar2);
                                                            return pcVar5;
                                                          }
                                                        }
                                                        local_78 = *(code **)(param_1 + 0x60);
                                                        uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar9 = DAT_23ed6a4f8;
                                                        uVar16 = 0x3d;
                                                        goto joined_r0x00023e2fb923;
                                                      }
                                                      goto LAB_23e2fc803;
                                                    }
                                                    local_78 = *(code **)(param_1 + 0x60);
                                                    uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                                    local_68[0] = *(longlong **)(param_1 + 0x70);
                                                    uVar16 = 0x3c;
                                                    uVar17 = 0x3c;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar10 = *plVar10 + -1;
                                                    lVar11 = *plVar10;
                                                  }
                                                  plVar8 = local_68[0];
                                                  plVar9 = DAT_23ed6a4f8;
                                                  if (lVar11 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                    plVar8 = local_68[0];
                                                    plVar9 = DAT_23ed6a4f8;
                                                    uVar16 = uVar17;
                                                  }
                                                  goto joined_r0x00023e2fb923;
                                                }
                                              }
LAB_23e2fc85f:
                                              local_78 = *(code **)(param_1 + 0x60);
                                              uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                              plVar8 = *(longlong **)(param_1 + 0x70);
                                              uVar16 = 0x3a;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plVar9 = DAT_23ed6a4f8;
                                              goto joined_r0x00023e2fb923;
                                            }
                                          }
                                          local_78 = *(code **)(param_1 + 0x60);
                                          uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                          uVar16 = 0x39;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plVar9 = DAT_23ed6a4f8;
                                          goto joined_r0x00023e2fb923;
                                        }
                                      }
                                      local_78 = *(code **)(param_1 + 0x60);
                                      uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                      plVar8 = *(longlong **)(param_1 + 0x70);
                                      uVar16 = 0x38;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plVar9 = DAT_23ed6a4f8;
                                      goto joined_r0x00023e2fb923;
                                    }
                                  }
                                }
                                local_78 = *(code **)(param_1 + 0x60);
                                uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                uVar16 = 0x37;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar9 = DAT_23ed6a4f8;
                                goto joined_r0x00023e2fb923;
                              }
                            }
                            local_78 = *(code **)(param_1 + 0x60);
                            uStack_70 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            uVar16 = 0x36;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar9 = DAT_23ed6a4f8;
                            goto joined_r0x00023e2fb923;
                          }
LAB_23e2facfe:
                          lStack_80 = lVar11;
                          local_88 = plVar8;
                          lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                          if (lVar11 == 0) {
LAB_23e2fc0fe:
                            local_78 = *(code **)(param_1 + 0x60);
                            uStack_70 = *(undefined8 *)(param_1 + 0x68);
                            local_68[0] = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e2fc090;
                          }
                          plVar10[4] = lVar11;
                          plVar8 = DAT_23eeac758;
                          *DAT_23eeac758 = *DAT_23eeac758 + 1;
                          plVar10[5] = (longlong)plVar8;
                          plVar8 = (longlong *)FUN_23e8f55b0();
                          lVar11 = DAT_23ed6cd28;
                          if (plVar8 == (longlong *)0x0) {
LAB_23e2fc3a8:
                            FUN_23e915740(param_1,&local_78,DAT_23eeac760);
                            goto LAB_23e2fc090;
                          }
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar14 == (longlong *)0x0) goto LAB_23e2fc4cb;
                            *plVar14 = *plVar14 + 1;
                            DAT_23ed6a4c0 = plVar14;
                          }
                          lStack_80 = lVar11;
                          local_88 = plVar8;
                          lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                          lVar11 = DAT_23eeac660;
                          if (lVar12 == 0) goto LAB_23e2fc0fe;
                          plVar10[6] = lVar12;
                          plVar8 = DAT_23eeac768;
                          lVar12 = *(longlong *)(lVar11 + 0x20);
                          *DAT_23eeac768 = *DAT_23eeac768 + 1;
                          plVar10[7] = (longlong)plVar8;
                          if (*(char *)(lVar12 + 10) == '\0') {
                            puVar13 = (undefined8 *)FUN_23a37a020(lVar11,DAT_23eeac770);
                            if (puVar13 == (undefined8 *)0x0) goto LAB_23e2fc1cc;
                            plVar8 = (longlong *)*puVar13;
LAB_23e2fc1c3:
                            if (plVar8 == (longlong *)0x0) goto LAB_23e2fc1cc;
                          }
                          else {
                            iVar7 = *(int *)(lVar12 + 0xc);
                            if (*(int *)(lVar12 + 0xc) == 0) {
                              *(int *)(lVar12 + 0xc) = DAT_23ec14e10;
                              iVar7 = DAT_23ec14e10;
                              DAT_23ec14e10 = DAT_23ec14e10 + 1;
                            }
                            if (DAT_23ec14dfc != iVar7) {
                              DAT_23ec14dfc = iVar7;
                              DAT_23eeaff60 =
                                   FUN_23e8cbd60(lVar12,DAT_23eeac770,
                                                 *(undefined8 *)(DAT_23eeac770 + 0x18));
                            }
                            if (-1 < DAT_23eeaff60) {
                              lVar11 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                              plVar8 = *(longlong **)(lVar11 + 8 + DAT_23eeaff60 * 0x10);
                              if (plVar8 != (longlong *)0x0) goto LAB_23e2fadef;
                              DAT_23eeaff60 =
                                   FUN_23e8cbd60(lVar12,DAT_23eeac770,
                                                 *(undefined8 *)(DAT_23eeac770 + 0x18));
                              if (-1 < DAT_23eeaff60) {
                                plVar8 = *(longlong **)(lVar11 + 8 + DAT_23eeaff60 * 0x10);
                                goto LAB_23e2fc1c3;
                              }
                            }
LAB_23e2fc1cc:
                            puVar13 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac770);
                            if ((puVar13 == (undefined8 *)0x0) ||
                               (plVar8 = (longlong *)*puVar13, plVar8 == (longlong *)0x0)) {
                              FUN_23e915740(param_1,&local_78,DAT_23eeac770);
                              goto LAB_23e2fc090;
                            }
                          }
LAB_23e2fadef:
                          lVar11 = DAT_23ed6cd28;
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar14 == (longlong *)0x0) goto LAB_23e2fc4cb;
                            *plVar14 = *plVar14 + 1;
                            DAT_23ed6a4c0 = plVar14;
                          }
                          lStack_80 = lVar11;
                          local_88 = plVar8;
                          lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                          if (lVar11 == 0) goto LAB_23e2fc0fe;
                          plVar10[8] = lVar11;
                          plVar8 = DAT_23eeac758;
                          *DAT_23eeac758 = *DAT_23eeac758 + 1;
                          plVar10[9] = (longlong)plVar8;
                          plVar8 = (longlong *)FUN_23e8f55b0();
                          lVar11 = DAT_23ed6cd28;
                          if (plVar8 == (longlong *)0x0) goto LAB_23e2fc3a8;
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar14 == (longlong *)0x0) goto LAB_23e2fc4cb;
                            *plVar14 = *plVar14 + 1;
                            DAT_23ed6a4c0 = plVar14;
                          }
                          lStack_80 = lVar11;
                          local_88 = plVar8;
                          lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                          lVar11 = DAT_23eeac660;
                          if (lVar12 == 0) goto LAB_23e2fc0fe;
                          plVar10[10] = lVar12;
                          plVar8 = DAT_23eeac778;
                          lVar12 = *(longlong *)(lVar11 + 0x20);
                          *DAT_23eeac778 = *DAT_23eeac778 + 1;
                          plVar10[0xb] = (longlong)plVar8;
                          if (*(char *)(lVar12 + 10) == '\0') {
                            puVar13 = (undefined8 *)FUN_23a37a020(lVar11,DAT_23eeac780);
                            if (puVar13 == (undefined8 *)0x0) goto LAB_23e2fc2ef;
                            plVar8 = (longlong *)*puVar13;
LAB_23e2fc2e6:
                            if (plVar8 == (longlong *)0x0) goto LAB_23e2fc2ef;
LAB_23e2faef6:
                            lVar11 = DAT_23ed6cd28;
                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                              plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                              if (plVar14 == (longlong *)0x0) goto LAB_23e2fc4cb;
                              *plVar14 = *plVar14 + 1;
                              DAT_23ed6a4c0 = plVar14;
                            }
                            lStack_80 = lVar11;
                            local_88 = plVar8;
                            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                            lVar11 = DAT_23eeac660;
                            if (lVar12 != 0) {
                              plVar10[0xc] = lVar12;
                              plVar8 = DAT_23eeac758;
                              lVar12 = *(longlong *)(lVar11 + 0x20);
                              *DAT_23eeac758 = *DAT_23eeac758 + 1;
                              plVar10[0xd] = (longlong)plVar8;
                              if (*(char *)(lVar12 + 10) == '\0') {
                                puVar13 = (undefined8 *)FUN_23a37a020(lVar11,DAT_23eeac788);
                                if (puVar13 == (undefined8 *)0x0) goto LAB_23e2fc435;
                                plVar8 = (longlong *)*puVar13;
LAB_23e2fc42c:
                                if (plVar8 == (longlong *)0x0) goto LAB_23e2fc435;
                              }
                              else {
                                iVar7 = *(int *)(lVar12 + 0xc);
                                if (*(int *)(lVar12 + 0xc) == 0) {
                                  *(int *)(lVar12 + 0xc) = DAT_23ec14e10;
                                  iVar7 = DAT_23ec14e10;
                                  DAT_23ec14e10 = DAT_23ec14e10 + 1;
                                }
                                if (DAT_23ec14e04 != iVar7) {
                                  DAT_23ec14e04 = iVar7;
                                  DAT_23eeaff70 =
                                       FUN_23e8cbd60(lVar12,DAT_23eeac788,
                                                     *(undefined8 *)(DAT_23eeac788 + 0x18));
                                }
                                if (-1 < DAT_23eeaff70) {
                                  lVar11 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                                  plVar8 = *(longlong **)(lVar11 + 8 + DAT_23eeaff70 * 0x10);
                                  if (plVar8 != (longlong *)0x0) goto LAB_23e2fafab;
                                  DAT_23eeaff70 =
                                       FUN_23e8cbd60(lVar12,DAT_23eeac788,
                                                     *(undefined8 *)(DAT_23eeac788 + 0x18));
                                  if (-1 < DAT_23eeaff70) {
                                    plVar8 = *(longlong **)(lVar11 + 8 + DAT_23eeaff70 * 0x10);
                                    goto LAB_23e2fc42c;
                                  }
                                }
LAB_23e2fc435:
                                puVar13 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac788);
                                if ((puVar13 == (undefined8 *)0x0) ||
                                   (plVar8 = (longlong *)*puVar13, plVar8 == (longlong *)0x0)) {
                                  FUN_23e915740(param_1,&local_78,DAT_23eeac788);
                                  goto LAB_23e2fc32a;
                                }
                              }
LAB_23e2fafab:
                              lVar11 = DAT_23ed6cd28;
                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar14 == (longlong *)0x0) goto LAB_23e2fc4cb;
                                *plVar14 = *plVar14 + 1;
                                DAT_23ed6a4c0 = plVar14;
                              }
                              lStack_80 = lVar11;
                              local_88 = plVar8;
                              lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                              if (lVar11 != 0) {
                                plVar10[0xe] = lVar11;
                                plVar8 = DAT_23eeac790;
                                lVar11 = DAT_23ed6cd28;
                                *DAT_23eeac790 = *DAT_23eeac790 + 1;
                                plVar10[0xf] = (longlong)plVar8;
                                plVar8 = (longlong *)PyUnicode_Join(lVar11,plVar10);
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                                }
                                if (plVar8 == (longlong *)0x0) {
                                  local_68[0] = *(longlong **)(param_1 + 0x70);
                                  uVar16 = 0x30;
                                  local_78 = *(code **)(param_1 + 0x60);
                                  uStack_70 = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  lVar11 = *plVar9;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar9 = lVar11 + -1;
                                  plVar8 = local_68[0];
                                  plVar9 = DAT_23ed6a4f8;
                                  if (lVar11 + -1 == 0) {
                                    FUN_23a334bc0();
                                    uVar16 = 0x30;
                                    plVar8 = local_68[0];
                                    plVar9 = DAT_23ed6a4f8;
                                  }
                                  goto joined_r0x00023e2fb923;
                                }
                                *(undefined4 *)(plVar3 + 5) = 0x30;
                                plVar10 = (longlong *)FUN_23e914090(param_1,plVar9,plVar8);
                                lVar11 = *plVar9;
                                *plVar9 = lVar11 + -1;
                                if (lVar11 + -1 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                *plVar8 = *plVar8 + -1;
                                if (*plVar8 == 0) {
                                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                                }
                                if (plVar10 == (longlong *)0x0) goto LAB_23e2fc20c;
                                *plVar10 = *plVar10 + -1;
                                if (*plVar10 == 0) {
                                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                                }
                                puVar18 = *(undefined8 **)(DAT_23eeac660 + 0x20);
                                if (*(char *)((longlong)puVar18 + 10) != '\0') {
                                  iVar7 = *(int *)((longlong)puVar18 + 0xc);
                                  if (*(int *)((longlong)puVar18 + 0xc) == 0) {
                                    *(int *)((longlong)puVar18 + 0xc) = DAT_23ec14e10;
                                    iVar7 = DAT_23ec14e10;
                                    DAT_23ec14e10 = DAT_23ec14e10 + 1;
                                  }
                                  if (DAT_23ec14e08 != iVar7) goto LAB_23e2fc4de;
                                  goto LAB_23e2fb0bc;
                                }
                                plVar8 = (longlong *)FUN_23a37a020(DAT_23eeac660,DAT_23eeac798);
                                if (plVar8 != (longlong *)0x0) {
                                  lVar11 = *plVar8;
                                  goto LAB_23e2fc552;
                                }
                                goto LAB_23e2fc55b;
                              }
                            }
                            local_78 = *(code **)(param_1 + 0x60);
                            uStack_70 = *(undefined8 *)(param_1 + 0x68);
                            local_68[0] = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          else {
                            iVar7 = *(int *)(lVar12 + 0xc);
                            if (*(int *)(lVar12 + 0xc) == 0) {
                              *(int *)(lVar12 + 0xc) = DAT_23ec14e10;
                              iVar7 = DAT_23ec14e10;
                              DAT_23ec14e10 = DAT_23ec14e10 + 1;
                            }
                            if (DAT_23ec14e00 != iVar7) {
                              DAT_23ec14e00 = iVar7;
                              DAT_23eeaff68 =
                                   FUN_23e8cbd60(lVar12,DAT_23eeac780,
                                                 *(undefined8 *)(DAT_23eeac780 + 0x18));
                            }
                            if (-1 < DAT_23eeaff68) {
                              lVar11 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                              plVar8 = *(longlong **)(lVar11 + 8 + DAT_23eeaff68 * 0x10);
                              if (plVar8 != (longlong *)0x0) goto LAB_23e2faef6;
                              DAT_23eeaff68 =
                                   FUN_23e8cbd60(lVar12,DAT_23eeac780,
                                                 *(undefined8 *)(DAT_23eeac780 + 0x18));
                              if (-1 < DAT_23eeaff68) {
                                plVar8 = *(longlong **)(lVar11 + 8 + DAT_23eeaff68 * 0x10);
                                goto LAB_23e2fc2e6;
                              }
                            }
LAB_23e2fc2ef:
                            puVar13 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac780);
                            if ((puVar13 != (undefined8 *)0x0) &&
                               (plVar8 = (longlong *)*puVar13, plVar8 != (longlong *)0x0))
                            goto LAB_23e2faef6;
                            FUN_23e915740(param_1,&local_78,DAT_23eeac780);
                          }
LAB_23e2fc32a:
                          uVar16 = 0x32;
                        }
                        else {
                          iVar7 = *(int *)(lVar11 + 0xc);
                          if (*(int *)(lVar11 + 0xc) == 0) {
                            *(int *)(lVar11 + 0xc) = DAT_23ec14e10;
                            iVar7 = DAT_23ec14e10;
                            DAT_23ec14e10 = DAT_23ec14e10 + 1;
                          }
                          if (DAT_23ec14df8 != iVar7) {
                            DAT_23ec14df8 = iVar7;
                            DAT_23eeaff58 =
                                 FUN_23e8cbd60(lVar11,DAT_23eeac750,
                                               *(undefined8 *)(DAT_23eeac750 + 0x18));
                          }
                          if (-1 < DAT_23eeaff58) {
                            lVar12 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
                            plVar8 = *(longlong **)(lVar12 + 8 + DAT_23eeaff58 * 0x10);
                            if (plVar8 != (longlong *)0x0) goto LAB_23e2face1;
                            DAT_23eeaff58 =
                                 FUN_23e8cbd60(lVar11,DAT_23eeac750,
                                               *(undefined8 *)(DAT_23eeac750 + 0x18));
                            if (-1 < DAT_23eeaff58) {
                              plVar8 = *(longlong **)(lVar12 + 8 + DAT_23eeaff58 * 0x10);
                              goto LAB_23e2fc04c;
                            }
                          }
LAB_23e2fc055:
                          puVar18 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeac750);
                          if ((puVar18 != (undefined8 *)0x0) &&
                             (plVar8 = (longlong *)*puVar18, plVar8 != (longlong *)0x0))
                          goto LAB_23e2face1;
                          FUN_23e915740(param_1,&local_78,DAT_23eeac750);
LAB_23e2fc090:
                          uVar16 = 0x31;
                        }
                        lVar11 = *plVar9;
                        *plVar9 = lVar11 + -1;
                        if (lVar11 + -1 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        *plVar10 = *plVar10 + -1;
                        lVar11 = *plVar10;
                        goto joined_r0x00023e2fbe2c;
                      }
                    }
LAB_23e2fbe50:
                    local_78 = *(code **)(param_1 + 0x60);
                    uStack_70 = *(undefined8 *)(param_1 + 0x68);
                    plVar8 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x2c;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar9 = DAT_23ed6a4f8;
                    goto joined_r0x00023e2fb923;
                  }
                }
LAB_23e2fbd70:
                local_78 = *(code **)(param_1 + 0x60);
                uStack_70 = *(undefined8 *)(param_1 + 0x68);
                plVar8 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0x2b;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar9 = DAT_23ed6a4f8;
              }
              goto joined_r0x00023e2fb923;
            }
          }
LAB_23e2fba30:
          local_78 = *(code **)(param_1 + 0x60);
          uStack_70 = *(undefined8 *)(param_1 + 0x68);
          plVar8 = *(longlong **)(param_1 + 0x70);
          uVar16 = 0x2a;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar9 = DAT_23ed6a4f8;
          goto joined_r0x00023e2fb923;
        }
      }
      local_78 = *(code **)(param_1 + 0x60);
      uStack_70 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar16 = 0x29;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = DAT_23ed6a4f8;
      goto joined_r0x00023e2fb923;
    }
  }
  local_78 = *(code **)(param_1 + 0x60);
  uStack_70 = *(undefined8 *)(param_1 + 0x68);
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar9 = DAT_23ed6a4f8;
  uVar16 = 0x25;
joined_r0x00023e2fb923:
  DAT_23ed6a4f8 = plVar9;
  local_68[0] = plVar8;
  if (plVar8 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar12 = plVar9[-1];
    puVar18 = *(undefined8 **)(lVar11 + 8);
    *puVar18 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar18;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar8 = plVar9;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))(local_68[0]);
    }
  }
  else if ((longlong *)plVar8[3] != plVar3) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar11 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar12 = plVar9[-1];
    puVar18 = *(undefined8 **)(lVar11 + 8);
    *puVar18 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar18;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    plVar8 = plVar9;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))();
    }
  }
  local_68[0] = plVar8;
  FUN_23e8bba40(plVar3,&DAT_23ec5b343,plVar1,plVar2,*(undefined8 *)(param_2 + 0xd8));
  if (DAT_23eeaff90 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeaff90 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar11 + 0x28);
  plVar3 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78,uStack_70,local_68[0]);
  return (code *)0x0;
}
