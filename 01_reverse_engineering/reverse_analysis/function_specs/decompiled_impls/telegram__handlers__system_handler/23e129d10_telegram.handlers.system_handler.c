/* ===== 23e129d10 telegram.handlers.system_handler:36 ===== */
/* ghidra_name=FUN_23e129d10 entry=23e129d10 size=2717 */

code * FUN_23e129d10(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  longlong *local_70;
  longlong *local_68;
  undefined8 local_60;
  longlong *local_58;
  
  plVar13 = DAT_23ed6a4e0;
  plVar2 = (longlong *)*param_3;
  lVar7 = param_3[1];
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
    plVar12 = DAT_23ed6a4e0;
  }
  else {
    plVar12 = (longlong *)*DAT_23ed6a4e0;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
    plVar8 = plVar12;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar8;
  }
  pcVar4 = _PyRuntime_exref;
  plVar13[2] = lVar7;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar13[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar13 + -2;
  plVar13[-2] = lVar7;
  plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar13 + -2;
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    DAT_23ed6a4e0 = (longlong *)*plVar12;
    *plVar12 = 1;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar4 = _PyRuntime_exref;
  plVar12[2] = 0;
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar12[-1];
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = plVar12 + -2;
  plVar12[-2] = lVar7;
  plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar7 + 8) = plVar12 + -2;
  uVar6 = FUN_23e8d7870(param_1,DAT_23eea8628);
  uVar16 = DAT_23eeaae98;
  *plVar13 = *plVar13 + 1;
  local_68 = plVar13;
  lVar7 = FUN_23e93e1e0(FUN_23e12a800,DAT_23eea8630,DAT_23eea8638,DAT_23eeaae48,0,uVar6,uVar16,0,
                        &local_68,1);
  plVar8 = DAT_23eeaae70;
  plVar12[2] = lVar7;
  if (plVar8 == (longlong *)0x0) {
LAB_23e129eac:
    plVar8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaae68,DAT_23eeaae98,0x20);
    DAT_23eeaae70 = plVar8;
  }
  else {
    lVar7 = *plVar8;
    if (1 < lVar7) {
      *plVar8 = lVar7 + -1;
      goto LAB_23e129eac;
    }
    if (plVar8[2] != 0) {
      *plVar8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e129eac;
    }
  }
  lVar7 = *(longlong *)(param_1 + 0x38);
  lVar14 = *(longlong *)(lVar7 + 8);
  plVar8[0xf] = lVar14;
  *(longlong **)(lVar7 + 8) = plVar8 + 9;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar8[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  uVar16 = DAT_23eea8640;
  *(undefined4 *)(plVar8 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,uVar16);
  if (plVar9 == (longlong *)0x0) {
LAB_23e12a360:
    local_70 = *(longlong **)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x2c;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar16 = *(undefined8 *)(param_1 + 0x68);
    plVar11 = DAT_23ed6a4f8;
  }
  else {
    lVar7 = *(longlong *)(DAT_23eea8590 + 0x20);
    if (*(char *)(lVar7 + 10) == '\0') {
      plVar10 = (longlong *)FUN_23a37a020(DAT_23eea8590,DAT_23eea8648);
      if (plVar10 == (longlong *)0x0) goto LAB_23e12a2d9;
      lVar14 = *plVar10;
LAB_23e12a718:
      if (lVar14 == 0) goto LAB_23e12a2d9;
LAB_23e129fc3:
      plVar10 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23eea8650);
      if (plVar10 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23eea8658);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 != (longlong *)0x0) {
          *(undefined4 *)(plVar8 + 5) = 0x2c;
          plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar11,DAT_23eea8660);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar10 != (longlong *)0x0) {
            *(undefined4 *)(plVar8 + 5) = 0x2c;
            plVar11 = (longlong *)FUN_23e914090(param_1,plVar9);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            uVar16 = DAT_23eea8668;
            if (plVar11 == (longlong *)0x0) goto LAB_23e12a360;
            lVar7 = *(longlong *)(DAT_23eea8590 + 0x20);
            if (*(char *)(lVar7 + 10) == '\0') {
              plVar9 = (longlong *)FUN_23a37a020(DAT_23eea8590,DAT_23eea8670);
              if (plVar9 == (longlong *)0x0) goto LAB_23e12a651;
              lVar14 = *plVar9;
LAB_23e12a798:
              if (lVar14 == 0) goto LAB_23e12a651;
            }
            else {
              iVar5 = *(int *)(lVar7 + 0xc);
              if (*(int *)(lVar7 + 0xc) == 0) {
                *(int *)(lVar7 + 0xc) = DAT_23ec14c30;
                iVar5 = DAT_23ec14c30;
                DAT_23ec14c30 = DAT_23ec14c30 + 1;
              }
              if (DAT_23ec14c2c != iVar5) {
                DAT_23ec14c2c = iVar5;
                DAT_23eeaae58 =
                     FUN_23e8cbd60(lVar7,DAT_23eea8670,*(undefined8 *)(DAT_23eea8670 + 0x18));
              }
              if (-1 < DAT_23eeaae58) {
                lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
                lVar14 = *(longlong *)(lVar1 + 8 + DAT_23eeaae58 * 0x10);
                if (lVar14 != 0) goto LAB_23e12a10f;
                DAT_23eeaae58 =
                     FUN_23e8cbd60(lVar7,DAT_23eea8670,*(undefined8 *)(DAT_23eea8670 + 0x18));
                if (-1 < DAT_23eeaae58) {
                  lVar14 = *(longlong *)(lVar1 + 8 + DAT_23eeaae58 * 0x10);
                  goto LAB_23e12a798;
                }
              }
LAB_23e12a651:
              plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8670);
              if ((plVar9 == (longlong *)0x0) || (lVar14 = *plVar9, lVar14 == 0)) {
                FUN_23e915740(param_1,&local_68,DAT_23eea8670);
                local_70 = local_68;
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                uVar15 = 0x2d;
                plVar10 = local_58;
                uVar16 = local_60;
                plVar11 = DAT_23ed6a4f8;
                goto joined_r0x00023e12a38a;
              }
            }
LAB_23e12a10f:
            uVar6 = _PyDict_NewPresized(2);
            PyDict_SetItem(uVar6,uVar16,lVar14);
            pcVar4 = _Py_NoneStruct_exref;
            PyDict_SetItem(uVar6,DAT_23eea8678,_Py_NoneStruct_exref);
            uVar16 = DAT_23eea8680;
            *plVar12 = *plVar12 + 1;
            local_68 = plVar12;
            plVar9 = (longlong *)
                     FUN_23e93e1e0(FUN_23e12ae30,DAT_23eea8688,DAT_23eea8690,DAT_23eeaae60,0,uVar6,
                                   DAT_23eeaae98,uVar16,&local_68,1);
            *(undefined4 *)(plVar8 + 5) = 0x2c;
            plVar10 = (longlong *)FUN_23e914090(param_1,plVar11,plVar9);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            if (plVar10 != (longlong *)0x0) {
              lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar8 = *(longlong **)(lVar7 + 0x28);
              plVar9 = (longlong *)plVar8[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
              *(undefined4 *)(plVar8 + 8) = 0xffffffff;
              if (plVar9 != (longlong *)0x0) {
                plVar8[2] = 0;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              *(longlong *)pcVar4 = *(longlong *)pcVar4 + 1;
              plVar8[0xf] = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              lVar7 = *plVar2;
              *plVar2 = lVar7 + -1;
              if (lVar7 + -1 != 0) {
                return pcVar4;
              }
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return pcVar4;
            }
            goto LAB_23e12a360;
          }
        }
      }
      local_70 = *(longlong **)(param_1 + 0x60);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar16 = *(undefined8 *)(param_1 + 0x68);
    }
    else {
      iVar5 = *(int *)(lVar7 + 0xc);
      if (*(int *)(lVar7 + 0xc) == 0) {
        *(int *)(lVar7 + 0xc) = DAT_23ec14c30;
        iVar5 = DAT_23ec14c30;
        DAT_23ec14c30 = DAT_23ec14c30 + 1;
      }
      if (DAT_23ec14c28 != iVar5) {
        DAT_23ec14c28 = iVar5;
        DAT_23eeaae50 = FUN_23e8cbd60(lVar7,DAT_23eea8648,*(undefined8 *)(DAT_23eea8648 + 0x18));
      }
      if (-1 < DAT_23eeaae50) {
        lVar1 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
        lVar14 = *(longlong *)(lVar1 + 8 + DAT_23eeaae50 * 0x10);
        if (lVar14 != 0) goto LAB_23e129fc3;
        DAT_23eeaae50 = FUN_23e8cbd60(lVar7,DAT_23eea8648,*(undefined8 *)(DAT_23eea8648 + 0x18));
        if (-1 < DAT_23eeaae50) {
          lVar14 = *(longlong *)(lVar1 + 8 + DAT_23eeaae50 * 0x10);
          goto LAB_23e12a718;
        }
      }
LAB_23e12a2d9:
      plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eea8648);
      if ((plVar10 != (longlong *)0x0) && (lVar14 = *plVar10, lVar14 != 0)) goto LAB_23e129fc3;
      FUN_23e915740(param_1,&local_68,DAT_23eea8648);
      local_70 = local_68;
      plVar10 = local_58;
      uVar16 = local_60;
    }
    *plVar9 = *plVar9 + -1;
    uVar15 = 0x2c;
    plVar11 = DAT_23ed6a4f8;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar15 = 0x2c;
      plVar11 = DAT_23ed6a4f8;
    }
  }
joined_r0x00023e12a38a:
  DAT_23ed6a4f8 = plVar11;
  if (plVar10 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar7 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar15;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar14 = plVar11[-1];
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = plVar11 + -2;
    plVar11[-2] = lVar7;
    plVar11[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar7 + 8) = plVar11 + -2;
    plVar9 = plVar11;
  }
  else {
    plVar9 = plVar10;
    if ((longlong *)plVar10[3] != plVar8) {
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar4 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar8;
      *plVar8 = *plVar8 + 1;
      lVar7 = *(longlong *)(pcVar4 + 0x1f8);
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar15;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar14 = plVar11[-1];
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = plVar11 + -2;
      plVar11[-2] = lVar7;
      plVar11[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar3;
      lVar14 = *plVar10;
      *(longlong **)(lVar7 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar10;
      plVar9 = plVar11;
      if (lVar14 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar8,&DAT_23ec5a38a,plVar2,plVar13,plVar12,0);
  if (DAT_23eeaae70 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    DAT_23eeaae70 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar7 + 0x28);
  plVar10 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  lVar7 = *plVar2;
  *plVar2 = lVar7 + -1;
  if (lVar7 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_70,uVar16,plVar9);
  return (code *)0x0;
}
