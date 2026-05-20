/* ===== 23e2da250 ui.hotkey_dialog:27 ===== */
/* ghidra_name=FUN_23e2da250 entry=23e2da250 size=11415 */

/* WARNING: Type propagation algorithm not settling */

code * FUN_23e2da250(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined4 uVar17;
  longlong lVar18;
  longlong *local_a0;
  longlong *local_98;
  longlong *local_90;
  undefined8 local_88;
  longlong *local_78;
  undefined8 uStack_70;
  longlong *local_68;
  
  plVar9 = DAT_23eeb0258;
  param_3 = (longlong *)*param_3;
  if (DAT_23eeb0258 == (longlong *)0x0) {
LAB_23e2da29a:
    DAT_23eeb0258 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0250,DAT_23eeb0268,0x40);
  }
  else {
    lVar10 = *DAT_23eeb0258;
    if (1 < lVar10) {
      *DAT_23eeb0258 = lVar10 + -1;
      goto LAB_23e2da29a;
    }
    if (DAT_23eeb0258[2] != 0) {
      *DAT_23eeb0258 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e2da29a;
    }
  }
  plVar3 = DAT_23eeb0258;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eeb0258 + 9;
  lVar18 = *(longlong *)(lVar10 + 8);
  DAT_23eeb0258[0xf] = lVar18;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar18 = DAT_23eead8e0;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar10 = *(longlong *)(lVar18 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    plVar9 = (longlong *)FUN_23a37a020(lVar18,DAT_23eead438);
    if (plVar9 == (longlong *)0x0) goto LAB_23e2db219;
    lVar18 = *plVar9;
LAB_23e2db6b0:
    if (lVar18 == 0) goto LAB_23e2db219;
  }
  else {
    iVar7 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = DAT_23ec14e50;
      iVar7 = DAT_23ec14e50;
      DAT_23ec14e50 = DAT_23ec14e50 + 1;
    }
    if (DAT_23ec14e48 != iVar7) {
      DAT_23ec14e48 = iVar7;
      DAT_23eeb0238 = FUN_23e8cbd60(lVar10,DAT_23eead438,*(undefined8 *)(DAT_23eead438 + 0x18));
    }
    if (-1 < DAT_23eeb0238) {
      lVar1 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar18 = *(longlong *)(lVar1 + 8 + DAT_23eeb0238 * 0x10);
      if (lVar18 != 0) goto LAB_23e2da38a;
      DAT_23eeb0238 = FUN_23e8cbd60(lVar10,DAT_23eead438,*(undefined8 *)(DAT_23eead438 + 0x18));
      if (-1 < DAT_23eeb0238) {
        lVar18 = *(longlong *)(lVar1 + 8 + DAT_23eeb0238 * 0x10);
        goto LAB_23e2db6b0;
      }
    }
LAB_23e2db219:
    plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eead438);
    if ((plVar9 == (longlong *)0x0) || (lVar18 = *plVar9, lVar18 == 0)) {
      plVar13 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      FUN_23e915740(param_1,&local_78,DAT_23eead438);
      uVar17 = 0x1d;
      local_98 = (longlong *)0x0;
      local_a0 = (longlong *)0x0;
      local_90 = local_78;
      local_88 = uStack_70;
      plVar9 = local_68;
      goto LAB_23e2db2a0;
    }
  }
LAB_23e2da38a:
  *(undefined4 *)(plVar3 + 5) = 0x1d;
  plVar8 = (longlong *)FUN_23e914090(param_1,lVar18,param_3);
  lVar10 = DAT_23eead448;
  if (plVar8 == (longlong *)0x0) {
    local_90 = *(longlong **)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_88 = *(undefined8 *)(param_1 + 0x68);
    uVar17 = 0x1d;
    local_98 = (longlong *)0x0;
    local_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2db2a0;
  }
  *(undefined4 *)(plVar3 + 5) = 0x1e;
  plVar9 = (longlong *)FUN_23e95a860(param_1,plVar8,DAT_23eead440,lVar10 + 0x18);
  if (plVar9 == (longlong *)0x0) {
    local_90 = *(longlong **)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    uVar17 = 0x1e;
    local_88 = *(undefined8 *)(param_1 + 0x68);
    local_98 = (longlong *)0x0;
    local_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2db2a0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar10 = DAT_23eead458;
  *(undefined4 *)(plVar3 + 5) = 0x1f;
  plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23eead450,*(undefined8 *)(lVar10 + 0x18));
  if (plVar9 == (longlong *)0x0) {
    local_90 = *(longlong **)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    uVar17 = 0x1f;
    local_88 = *(undefined8 *)(param_1 + 0x68);
    local_98 = (longlong *)0x0;
    local_a0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2db2a0;
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  lVar10 = FUN_23e8f63e0();
  if (lVar10 == 0) {
    FUN_23e915740(param_1,&local_78,DAT_23eead460);
    local_90 = local_78;
    local_88 = uStack_70;
    plVar11 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x22;
    plVar11 = (longlong *)FUN_23e94bb80(param_1,lVar10,DAT_23eead468);
    if (plVar11 != (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23eead470);
      if (plVar12 == (longlong *)0x0) {
        local_90 = *(longlong **)(param_1 + 0x60);
        plVar9 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = (longlong *)0x0;
        uVar17 = 0x23;
        local_88 = *(undefined8 *)(param_1 + 0x68);
        local_98 = (longlong *)0x0;
        local_a0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar12 = (longlong *)0x0;
        goto LAB_23e2db2a0;
      }
      lVar10 = FUN_23e8f6290();
      if (lVar10 == 0) {
        FUN_23e915740(param_1,&local_78,DAT_23eead478);
        *plVar12 = *plVar12 + -1;
        lVar10 = *plVar12;
        local_90 = local_78;
        local_88 = uStack_70;
        plVar9 = local_68;
joined_r0x00023e2dba8d:
        if (lVar10 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead480);
        if (plVar9 == (longlong *)0x0) {
          local_90 = *(longlong **)(param_1 + 0x60);
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_88 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar12 = *plVar12 + -1;
          lVar10 = *plVar12;
          goto joined_r0x00023e2dba8d;
        }
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead488);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar13 == (longlong *)0x0) {
          local_90 = *(longlong **)(param_1 + 0x60);
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_88 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          local_98 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          uVar17 = 0x23;
          local_a0 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          goto LAB_23e2db2a0;
        }
        *(undefined4 *)(plVar3 + 5) = 0x23;
        plVar9 = (longlong *)FUN_23e914090(param_1,plVar12,plVar13);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          lVar10 = *(longlong *)(DAT_23eead8e0 + 0x20);
          if (*(char *)(lVar10 + 10) == '\0') {
            plVar9 = (longlong *)FUN_23a37a020(DAT_23eead8e0,DAT_23eead490);
            if (plVar9 == (longlong *)0x0) goto LAB_23e2db6e0;
            lVar10 = *plVar9;
LAB_23e2db6d4:
            if (lVar10 == 0) goto LAB_23e2db6e0;
          }
          else {
            iVar7 = *(int *)(lVar10 + 0xc);
            if (*(int *)(lVar10 + 0xc) == 0) {
              *(int *)(lVar10 + 0xc) = DAT_23ec14e50;
              iVar7 = DAT_23ec14e50;
              DAT_23ec14e50 = DAT_23ec14e50 + 1;
            }
            if (DAT_23ec14e4c != iVar7) {
              DAT_23ec14e4c = iVar7;
              DAT_23eeb0240 =
                   FUN_23e8cbd60(lVar10,DAT_23eead490,*(undefined8 *)(DAT_23eead490 + 0x18));
            }
            if (-1 < DAT_23eeb0240) {
              lVar18 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
              if (*(longlong *)(lVar18 + 8 + DAT_23eeb0240 * 0x10) != 0) goto LAB_23e2da57f;
              DAT_23eeb0240 =
                   FUN_23e8cbd60(lVar10,DAT_23eead490,*(undefined8 *)(DAT_23eead490 + 0x18));
              if (-1 < DAT_23eeb0240) {
                lVar10 = *(longlong *)(lVar18 + 8 + DAT_23eeb0240 * 0x10);
                goto LAB_23e2db6d4;
              }
            }
LAB_23e2db6e0:
            plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eead490);
            if ((plVar9 == (longlong *)0x0) || (*plVar9 == 0)) {
              plVar13 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              FUN_23e915740(param_1,&local_78,DAT_23eead490);
              uVar17 = 0x24;
              local_98 = (longlong *)0x0;
              local_a0 = (longlong *)0x0;
              local_90 = local_78;
              local_88 = uStack_70;
              plVar9 = local_68;
              goto LAB_23e2db2a0;
            }
          }
LAB_23e2da57f:
          *(undefined4 *)(plVar3 + 5) = 0x24;
          plVar14 = (longlong *)FUN_23e91a870(param_1);
          lVar10 = DAT_23eead4a0;
          if (plVar14 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar12 = (longlong *)0x0;
            uVar17 = 0x24;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2db2a0;
          }
          *(undefined4 *)(plVar3 + 5) = 0x25;
          plVar9 = (longlong *)
                   FUN_23e915840(param_1,plVar14,DAT_23eead498,*(undefined8 *)(lVar10 + 0x18));
          if (plVar9 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x25;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          lVar10 = DAT_23eead410;
          *(undefined4 *)(plVar3 + 5) = 0x26;
          plVar9 = (longlong *)
                   FUN_23e915840(param_1,plVar14,DAT_23eead4a8,*(undefined8 *)(lVar10 + 0x18));
          if (plVar9 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x26;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *(undefined4 *)(plVar3 + 5) = 0x27;
          plVar9 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23eead4b0,plVar14);
          if (plVar9 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x27;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *(undefined4 *)(plVar3 + 5) = 0x28;
          plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23eead4b8,plVar11);
          if (plVar9 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x28;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar12 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eead3e0);
          if (plVar12 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x2b;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          iVar7 = FUN_23a35f020(plVar12);
          lVar10 = *plVar12 + -1;
          if (iVar7 == -1) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar12 = lVar10;
            if (lVar10 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            local_98 = (longlong *)0x0;
            uVar17 = 0x2b;
            plVar13 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          *plVar12 = lVar10;
          if (lVar10 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar12 = (longlong *)0x0;
          if (iVar7 != 0) {
            plVar12 = (longlong *)FUN_23e8f63e0();
            plVar9 = DAT_23eead4c0;
            if (plVar12 == (longlong *)0x0) {
              plVar13 = (longlong *)0x0;
              FUN_23e915740(param_1,&local_78,DAT_23eead460);
              uVar17 = 0x2c;
              local_98 = (longlong *)0x0;
              local_a0 = (longlong *)0x0;
              local_90 = local_78;
              local_88 = uStack_70;
              plVar9 = local_68;
              goto LAB_23e2db2a0;
            }
            lVar10 = *(longlong *)(param_1 + 0x10);
            local_a0 = *(longlong **)(lVar10 + 0xe20);
            if (local_a0 == (longlong *)0x0) {
              local_a0 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar18 = local_a0[3];
              *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
              *(longlong *)(lVar10 + 0xe20) = lVar18;
              *local_a0 = 1;
            }
            pcVar5 = _PyRuntime_exref;
            local_a0[4] = 0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
            lVar18 = local_a0[-1];
            puVar2 = *(undefined8 **)(lVar10 + 8);
            *puVar2 = local_a0 + -2;
            local_a0[-2] = lVar10;
            local_a0[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar10 + 8) = local_a0 + -2;
            uVar4 = DAT_23eead3e0;
            *plVar9 = *plVar9 + 1;
            local_a0[3] = (longlong)plVar9;
            plVar13 = (longlong *)FUN_23e8bc2f0(param_3,uVar4);
            uVar4 = DAT_23ed6cd28;
            if (plVar13 != (longlong *)0x0) {
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar9 != (longlong *)0x0) {
                  *plVar9 = *plVar9 + 1;
                  DAT_23ed6a4c0 = plVar9;
                  goto LAB_23e2dbbd6;
                }
                PyErr_PrintEx(0,0);
                Py_Exit();
LAB_23e2dc9a6:
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                uVar17 = 0x49;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e2db2a0;
              }
LAB_23e2dbbd6:
              uStack_70 = uVar4;
              local_78 = plVar13;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (lVar10 != 0) {
                local_a0[4] = lVar10;
                plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,local_a0);
                *local_a0 = *local_a0 + -1;
                if (*local_a0 == 0) {
                  (**(code **)(local_a0[1] + 0x30))(local_a0);
                }
                if (plVar9 == (longlong *)0x0) {
                  local_90 = *(longlong **)(param_1 + 0x60);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  plVar12 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar17 = 0x2c;
                  local_88 = *(undefined8 *)(param_1 + 0x68);
                  local_98 = (longlong *)0x0;
                  local_a0 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23e2db2a0;
                }
                *(undefined4 *)(plVar3 + 5) = 0x2c;
                plVar12 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (plVar12 == (longlong *)0x0) {
                  local_90 = *(longlong **)(param_1 + 0x60);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  plVar13 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar17 = 0x2c;
                  local_88 = *(undefined8 *)(param_1 + 0x68);
                  local_98 = (longlong *)0x0;
                  local_a0 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2db2a0;
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23eead470);
                if (plVar15 == (longlong *)0x0) {
                  local_90 = *(longlong **)(param_1 + 0x60);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  local_98 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar17 = 0x2d;
                  local_88 = *(undefined8 *)(param_1 + 0x68);
                  local_a0 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23e2db2a0;
                }
                lVar10 = FUN_23e8f6290();
                if (lVar10 == 0) {
                  FUN_23e915740(param_1,&local_78,DAT_23eead478);
                  *plVar15 = *plVar15 + -1;
                  lVar10 = *plVar15;
                  local_90 = local_78;
                  local_88 = uStack_70;
                  plVar9 = local_68;
                }
                else {
                  plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead480);
                  if (plVar9 != (longlong *)0x0) {
                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead488);
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    if (plVar13 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar15 = *plVar15 + -1;
                      local_98 = (longlong *)0x0;
                      if (*plVar15 == 0) {
                        plVar13 = (longlong *)0x0;
                        FUN_23a334bc0(plVar15);
                        uVar17 = 0x2d;
                        local_a0 = (longlong *)0x0;
                      }
                      else {
                        plVar13 = (longlong *)0x0;
                        uVar17 = 0x2d;
                        local_a0 = (longlong *)0x0;
                      }
                      goto LAB_23e2db2a0;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x2d;
                    plVar9 = (longlong *)FUN_23e914090(param_1,plVar15,plVar13);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    lVar10 = *plVar13;
                    *plVar13 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      (**(code **)(plVar13[1] + 0x30))();
                    }
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      plVar13 = (longlong *)0x0;
                      uVar17 = 0x2d;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_98 = (longlong *)0x0;
                      local_a0 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      (**(code **)(plVar9[1] + 0x30))();
                    }
                    lVar10 = DAT_23eead4d0;
                    *(undefined4 *)(plVar3 + 5) = 0x2e;
                    plVar9 = (longlong *)
                             FUN_23e915840(param_1,plVar12,DAT_23eead4c8,
                                           *(undefined8 *)(lVar10 + 0x18));
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x2e;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_98 = (longlong *)0x0;
                      local_a0 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x2f;
                    plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23eead4b8,plVar12);
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x2f;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_98 = (longlong *)0x0;
                      local_a0 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                    }
                    goto LAB_23e2da6d8;
                  }
                  local_90 = *(longlong **)(param_1 + 0x60);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_88 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar15 = *plVar15 + -1;
                  lVar10 = *plVar15;
                }
                if (lVar10 == 0) {
                  local_a0 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  FUN_23a334bc0(plVar15);
                  uVar17 = 0x2d;
                  local_98 = (longlong *)0x0;
                }
                else {
                  local_a0 = (longlong *)0x0;
                  local_98 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  uVar17 = 0x2d;
                }
                goto LAB_23e2db2a0;
              }
            }
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *local_a0 = *local_a0 + -1;
            if (*local_a0 == 0) {
              (**(code **)(local_a0[1] + 0x30))(local_a0);
            }
            local_98 = (longlong *)0x0;
            uVar17 = 0x2c;
            plVar13 = (longlong *)0x0;
            plVar12 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
LAB_23e2da6d8:
          lVar10 = FUN_23e8f63e0();
          if (lVar10 == 0) {
            FUN_23e915740(param_1,&local_78,DAT_23eead460);
            uVar17 = 0x32;
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            local_90 = local_78;
            local_88 = uStack_70;
            plVar13 = (longlong *)0x0;
            plVar9 = local_68;
            goto LAB_23e2db2a0;
          }
          *(undefined4 *)(plVar3 + 5) = 0x32;
          plVar9 = (longlong *)FUN_23e94bb80(param_1,lVar10,DAT_23eead4d8);
          if (plVar9 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            local_98 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x32;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          cVar6 = FUN_23e8d9ac0(param_3,DAT_23eead4e0,plVar9);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (cVar6 == '\0') {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x32;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2db2a0;
          }
          plVar9 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eead4e0);
          if (plVar9 == (longlong *)0x0) {
LAB_23e2dc11b:
            plVar13 = (longlong *)0x0;
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            local_98 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x33;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2db2a0;
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead470);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar15 == (longlong *)0x0) {
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar17 = 0x33;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            local_98 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_a0 = (longlong *)0x0;
            goto LAB_23e2db2a0;
          }
          lVar10 = FUN_23e8f6290();
          if (lVar10 == 0) {
            FUN_23e915740(param_1,&local_78,DAT_23eead478);
            local_90 = local_78;
            local_88 = uStack_70;
            plVar9 = local_68;
          }
          else {
            plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead480);
            if (plVar9 != (longlong *)0x0) {
              plVar13 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead488);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar13 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                lVar10 = *plVar15;
                *plVar15 = lVar10 + -1;
                local_98 = (longlong *)0x0;
                if (lVar10 + -1 == 0) {
                  plVar13 = (longlong *)0x0;
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                  uVar17 = 0x33;
                  local_a0 = (longlong *)0x0;
                }
                else {
                  local_a0 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  uVar17 = 0x33;
                }
                goto LAB_23e2db2a0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x33;
              plVar9 = (longlong *)FUN_23e914090(param_1,plVar15,plVar13);
              lVar10 = *plVar15;
              *plVar15 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar10 = *plVar13;
              *plVar13 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              if (plVar9 == (longlong *)0x0) goto LAB_23e2dc11b;
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eead4e0);
              lVar10 = DAT_23eead4f0;
              if (plVar9 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar17 = 0x34;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                local_a0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar13 = (longlong *)0x0;
                goto LAB_23e2db2a0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x34;
              plVar13 = (longlong *)
                        FUN_23e915840(param_1,plVar9,DAT_23eead4e8,*(undefined8 *)(lVar10 + 0x18));
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar13 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                plVar13 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar17 = 0x34;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                local_98 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_a0 = (longlong *)0x0;
                goto LAB_23e2db2a0;
              }
              lVar10 = *plVar13;
              *plVar13 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eead4e0);
              if (plVar9 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar17 = 0x35;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                local_a0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar13 = (longlong *)0x0;
                goto LAB_23e2db2a0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x35;
              plVar13 = (longlong *)FUN_23e915840(param_1,plVar9,DAT_23eead4c8);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar13 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                uVar17 = 0x35;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar13 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_a0 = (longlong *)0x0;
                goto LAB_23e2db2a0;
              }
              lVar10 = *plVar13;
              *plVar13 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23eead4b8);
              if (plVar15 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar17 = 0x40;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                local_a0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar13 = (longlong *)0x0;
                goto LAB_23e2db2a0;
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eead4e0);
              if (plVar9 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar15 = *plVar15 + -1;
                local_a0 = (longlong *)0x0;
                if (*plVar15 == 0) {
                  plVar13 = (longlong *)0x0;
                  FUN_23a334bc0(plVar15);
                  uVar17 = 0x40;
                  local_98 = (longlong *)0x0;
                }
                else {
                  plVar13 = (longlong *)0x0;
                  uVar17 = 0x40;
                  local_98 = (longlong *)0x0;
                }
                goto LAB_23e2db2a0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x40;
              plVar13 = (longlong *)FUN_23e914090(param_1,plVar15,plVar9);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar10 = *plVar9;
              *plVar9 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar9[1] + 0x30))();
              }
              if (plVar13 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_a0 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                uVar17 = 0x40;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_98 = (longlong *)0x0;
                goto LAB_23e2db2a0;
              }
              lVar10 = *plVar13;
              *plVar13 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              lVar10 = FUN_23e8f63e0();
              if (lVar10 == 0) {
                FUN_23e915740(param_1,&local_78,DAT_23eead460);
                local_98 = (longlong *)0x0;
                uVar17 = 0x43;
                local_90 = local_78;
                local_a0 = (longlong *)0x0;
                local_88 = uStack_70;
                plVar13 = (longlong *)0x0;
                plVar9 = local_68;
                goto LAB_23e2db2a0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x43;
              plVar13 = (longlong *)FUN_23e94bb80(param_1,lVar10);
              lVar10 = DAT_23eead508;
              if (plVar13 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                uVar17 = 0x43;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_a0 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e2db2a0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x49;
              local_a0 = (longlong *)
                         FUN_23e915840(param_1,plVar13,DAT_23eead4c8,*(undefined8 *)(lVar10 + 0x18))
              ;
              if (local_a0 == (longlong *)0x0) goto LAB_23e2dc9a6;
              lVar10 = *local_a0;
              *local_a0 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(local_a0[1] + 0x30))();
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar13);
              if (plVar15 == (longlong *)0x0) {
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_98 = (longlong *)0x0;
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_a0 = (longlong *)0x0;
                uVar17 = 0x4a;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e2db2a0;
              }
              lVar10 = FUN_23e8f6290();
              if (lVar10 == 0) {
                FUN_23e915740(param_1,&local_78);
                *plVar15 = *plVar15 + -1;
                lVar10 = *plVar15;
                local_90 = local_78;
                local_88 = uStack_70;
                plVar9 = local_68;
              }
              else {
                plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead480);
                if (plVar9 != (longlong *)0x0) {
                  plVar16 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead510);
                  lVar10 = *plVar9;
                  *plVar9 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    (**(code **)(plVar9[1] + 0x30))();
                  }
                  if (plVar16 == (longlong *)0x0) {
                    local_90 = *(longlong **)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    local_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar15 = *plVar15 + -1;
                    local_98 = (longlong *)0x0;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                      uVar17 = 0x4a;
                      local_a0 = (longlong *)0x0;
                    }
                    else {
                      uVar17 = 0x4a;
                      local_a0 = (longlong *)0x0;
                    }
                    goto LAB_23e2db2a0;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x4a;
                  plVar9 = (longlong *)FUN_23e914090(param_1,plVar15,plVar16);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  lVar10 = *plVar16;
                  *plVar16 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    (**(code **)(plVar16[1] + 0x30))();
                  }
                  if (plVar9 == (longlong *)0x0) {
                    local_90 = *(longlong **)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar17 = 0x4a;
                    local_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_98 = (longlong *)0x0;
                    local_a0 = (longlong *)0x0;
                    goto LAB_23e2db2a0;
                  }
                  lVar10 = *plVar9;
                  *plVar9 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x4b;
                  plVar9 = (longlong *)FUN_23e915840(param_1,plVar8);
                  if (plVar9 == (longlong *)0x0) {
                    local_90 = *(longlong **)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    local_98 = (longlong *)0x0;
                    uVar17 = 0x4b;
                    local_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    local_a0 = (longlong *)0x0;
                    goto LAB_23e2db2a0;
                  }
                  lVar10 = *plVar9;
                  *plVar9 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    (**(code **)(plVar9[1] + 0x30))();
                  }
                  lVar10 = FUN_23e8f6140();
                  if (lVar10 == 0) {
                    FUN_23e915740(param_1,&local_78,DAT_23eead518);
                    local_98 = (longlong *)0x0;
                    uVar17 = 0x4e;
                    local_90 = local_78;
                    local_88 = uStack_70;
                    local_a0 = (longlong *)0x0;
                    plVar9 = local_68;
                    goto LAB_23e2db2a0;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x4e;
                  local_a0 = (longlong *)FUN_23e91a870(param_1,lVar10);
                  if (local_a0 == (longlong *)0x0) {
                    local_90 = *(longlong **)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    local_98 = (longlong *)0x0;
                    uVar17 = 0x4e;
                    local_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e2db2a0;
                  }
                  plVar15 = (longlong *)FUN_23e8bc2f0(local_a0,DAT_23eead520);
                  if (plVar15 == (longlong *)0x0) {
                    local_90 = *(longlong **)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    local_98 = (longlong *)0x0;
                    uVar17 = 0x4f;
                    local_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e2db2a0;
                  }
                  lVar10 = FUN_23e8f6140();
                  if (lVar10 == 0) {
                    FUN_23e915740(param_1,&local_78,DAT_23eead518);
                    local_90 = local_78;
                    local_88 = uStack_70;
LAB_23e2dcb3b:
                    *plVar15 = *plVar15 + -1;
                    lVar10 = *plVar15;
                    uVar17 = 0x4f;
joined_r0x00023e2dcb44:
                    local_98 = (longlong *)0x0;
                    plVar9 = local_68;
                  }
                  else {
                    plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead528);
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e2dcb3b;
                    }
                    plVar16 = (longlong *)FUN_23e8bc2f0(plVar9);
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar16 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                        uVar17 = 0x4f;
                        local_98 = (longlong *)0x0;
                      }
                      else {
                        local_98 = (longlong *)0x0;
                        uVar17 = 0x4f;
                      }
                      goto LAB_23e2db2a0;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x4f;
                    plVar9 = (longlong *)FUN_23e914090(param_1,plVar15,plVar16);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0(plVar16);
                    }
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x4f;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_98 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    plVar15 = (longlong *)FUN_23e8bc2f0(local_a0,DAT_23eead538);
                    if (plVar15 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x50;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_98 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    lVar10 = FUN_23e8f6140();
                    if (lVar10 == 0) {
                      FUN_23e915740(param_1,&local_78,DAT_23eead518);
                      local_90 = local_78;
                      local_88 = uStack_70;
LAB_23e2dcd32:
                      *plVar15 = *plVar15 + -1;
                      lVar10 = *plVar15;
                      uVar17 = 0x50;
                      goto joined_r0x00023e2dcb44;
                    }
                    plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eead540);
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      goto LAB_23e2dcd32;
                    }
                    plVar16 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead548);
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar16 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                        uVar17 = 0x50;
                        local_98 = (longlong *)0x0;
                      }
                      else {
                        uVar17 = 0x50;
                        local_98 = (longlong *)0x0;
                      }
                      goto LAB_23e2db2a0;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x50;
                    plVar9 = (longlong *)FUN_23e914090(param_1,plVar15,plVar16);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                    }
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0(plVar16);
                    }
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x50;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_98 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x51;
                    plVar9 = (longlong *)FUN_23e915840(param_1,local_a0,DAT_23eead4c8);
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x51;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_98 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x52;
                    plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23eead4b8,local_a0);
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x52;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_98 = (longlong *)0x0;
                      goto LAB_23e2db2a0;
                    }
                    lVar10 = *plVar9;
                    *plVar9 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    lVar10 = *(longlong *)(DAT_23eead8e0 + 0x20);
                    if (*(char *)(lVar10 + 10) == '\0') {
                      plVar9 = (longlong *)FUN_23a37a020(DAT_23eead8e0,DAT_23eead558);
                      if (plVar9 == (longlong *)0x0) goto LAB_23e2dcc55;
                      lVar18 = *plVar9;
LAB_23e2dcc4c:
                      if (lVar18 == 0) goto LAB_23e2dcc55;
                    }
                    else {
                      iVar7 = *(int *)(lVar10 + 0xc);
                      if (*(int *)(lVar10 + 0xc) == 0) {
                        *(int *)(lVar10 + 0xc) = DAT_23ec14e50;
                        iVar7 = DAT_23ec14e50;
                        DAT_23ec14e50 = DAT_23ec14e50 + 1;
                      }
                      if (DAT_23ec14e54 != iVar7) {
                        DAT_23ec14e54 = iVar7;
                        DAT_23eeb0248 =
                             FUN_23e8cbd60(lVar10,DAT_23eead558,
                                           *(undefined8 *)(DAT_23eead558 + 0x18));
                      }
                      if (-1 < DAT_23eeb0248) {
                        lVar1 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                        lVar18 = *(longlong *)(lVar1 + 8 + DAT_23eeb0248 * 0x10);
                        if (lVar18 != 0) goto LAB_23e2daf74;
                        DAT_23eeb0248 =
                             FUN_23e8cbd60(lVar10,DAT_23eead558,
                                           *(undefined8 *)(DAT_23eead558 + 0x18));
                        if (-1 < DAT_23eeb0248) {
                          lVar18 = *(longlong *)(lVar1 + 8 + DAT_23eeb0248 * 0x10);
                          goto LAB_23e2dcc4c;
                        }
                      }
LAB_23e2dcc55:
                      plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eead558);
                      if ((plVar9 == (longlong *)0x0) || (lVar18 = *plVar9, lVar18 == 0)) {
                        FUN_23e915740(param_1,&local_78,DAT_23eead558);
                        local_98 = (longlong *)0x0;
                        uVar17 = 0x55;
                        local_90 = local_78;
                        local_88 = uStack_70;
                        plVar9 = local_68;
                        goto LAB_23e2db2a0;
                      }
                    }
LAB_23e2daf74:
                    *(undefined4 *)(plVar3 + 5) = 0x55;
                    local_98 = (longlong *)FUN_23e94bb80(param_1,lVar18,DAT_23eead560);
                    lVar10 = DAT_23eead568;
                    if (local_98 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x55;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      goto LAB_23e2db2a0;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x56;
                    plVar9 = (longlong *)
                             FUN_23e915840(param_1,local_98,DAT_23eead4e8,
                                           *(undefined8 *)(lVar10 + 0x18));
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x56;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      goto LAB_23e2db2a0;
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    lVar10 = DAT_23eead570;
                    *(undefined4 *)(plVar3 + 5) = 0x57;
                    plVar9 = (longlong *)
                             FUN_23e915840(param_1,local_98,DAT_23eead4c8,
                                           *(undefined8 *)(lVar10 + 0x18));
                    if (plVar9 == (longlong *)0x0) {
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 0x57;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      goto LAB_23e2db2a0;
                    }
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    plVar9 = (longlong *)FUN_23e8bc2f0(local_98,DAT_23eead578);
                    if (plVar9 == (longlong *)0x0) {
LAB_23e2dcbec:
                      local_90 = *(longlong **)(param_1 + 0x60);
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      uVar17 = 100;
                      local_88 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      goto LAB_23e2db2a0;
                    }
                    plVar15 = (longlong *)FUN_23e8bc2f0(plVar9,DAT_23eead580);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    if (plVar15 == (longlong *)0x0) goto LAB_23e2dcbec;
                    plVar9 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eead588);
                    if (plVar9 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 100;
                      plVar16 = (longlong *)FUN_23e914090(param_1,plVar15,plVar9);
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0(plVar9);
                      }
                      if (plVar16 != (longlong *)0x0) {
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        *(undefined4 *)(plVar3 + 5) = 0x65;
                        plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23eead4b8,local_98);
                        if (plVar9 != (longlong *)0x0) {
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            FUN_23a334bc0(plVar9);
                          }
                          FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                          pcVar5 = _Py_NoneStruct_exref;
                          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            FUN_23a334bc0(plVar8);
                          }
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            FUN_23a334bc0(plVar11);
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0(plVar14);
                          }
                          if ((plVar12 != (longlong *)0x0) &&
                             (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                            FUN_23a334bc0(plVar12);
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0(plVar13);
                          }
                          lVar10 = *local_a0;
                          *local_a0 = lVar10 + -1;
                          if (lVar10 + -1 == 0) {
                            FUN_23a334bc0(local_a0);
                          }
                          lVar10 = *local_98;
                          *local_98 = lVar10 + -1;
                          if (lVar10 + -1 == 0) {
                            FUN_23a334bc0(local_98);
                          }
                          lVar10 = *param_3;
                          *param_3 = lVar10 + -1;
                          if (lVar10 + -1 == 0) {
                            FUN_23a334bc0(param_3);
                            return pcVar5;
                          }
                          return pcVar5;
                        }
                        local_90 = *(longlong **)(param_1 + 0x60);
                        plVar9 = *(longlong **)(param_1 + 0x70);
                        uVar17 = 0x65;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_88 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e2db2a0;
                      }
                      goto LAB_23e2dcbec;
                    }
                    local_90 = *(longlong **)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar17 = 100;
                    local_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar15 = *plVar15 + -1;
                    lVar10 = *plVar15;
                  }
                  if (lVar10 == 0) {
                    FUN_23a334bc0(plVar15);
                  }
                  goto LAB_23e2db2a0;
                }
                local_90 = *(longlong **)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                local_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar15 = *plVar15 + -1;
                lVar10 = *plVar15;
              }
              if (lVar10 == 0) {
                local_a0 = (longlong *)0x0;
                FUN_23a334bc0(plVar15);
                uVar17 = 0x4a;
                local_98 = (longlong *)0x0;
              }
              else {
                local_a0 = (longlong *)0x0;
                uVar17 = 0x4a;
                local_98 = (longlong *)0x0;
              }
              goto LAB_23e2db2a0;
            }
            local_90 = *(longlong **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_88 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          plVar13 = (longlong *)0x0;
          lVar10 = *plVar15;
          *plVar15 = lVar10 + -1;
          if (lVar10 + -1 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
            uVar17 = 0x33;
            local_98 = (longlong *)0x0;
            local_a0 = (longlong *)0x0;
          }
          else {
            local_98 = (longlong *)0x0;
            uVar17 = 0x33;
            local_a0 = (longlong *)0x0;
          }
          goto LAB_23e2db2a0;
        }
        local_90 = *(longlong **)(param_1 + 0x60);
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_88 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      plVar14 = (longlong *)0x0;
      local_98 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      uVar17 = 0x23;
      local_a0 = (longlong *)0x0;
      goto LAB_23e2db2a0;
    }
    local_90 = *(longlong **)(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_88 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  local_98 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  local_a0 = (longlong *)0x0;
  uVar17 = 0x22;
  plVar9 = local_68;
LAB_23e2db2a0:
  plVar15 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar17;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar18 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar10 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar16 = plVar15;
  }
  else {
    plVar16 = plVar9;
    if ((longlong *)plVar9[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar16 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar16;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar15[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar15 + 0x24) = uVar17;
      pcVar5 = _PyRuntime_exref;
      *(undefined4 *)(plVar15 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = plVar15[-1];
      puVar2 = *(undefined8 **)(lVar10 + 8);
      *puVar2 = plVar15 + -2;
      plVar15[-2] = lVar10;
      plVar15[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
      lVar18 = *plVar9;
      *(longlong **)(lVar10 + 8) = plVar15 + -2;
      plVar15[2] = (longlong)plVar9;
      plVar16 = plVar15;
      if (lVar18 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar3,"oooooooo",param_3,plVar8,plVar11,plVar14,plVar12,plVar13,local_a0,local_98);
  if (DAT_23eeb0258 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeb0258 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar10 + 0x28);
  plVar3 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_a0 != (longlong *)0x0) &&
     (lVar10 = *local_a0, *local_a0 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_a0[1] + 0x30))(local_a0);
  }
  if ((local_98 != (longlong *)0x0) &&
     (lVar10 = *local_98, *local_98 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(local_98[1] + 0x30))(local_98);
  }
  lVar10 = *param_3;
  *param_3 = lVar10 + -1;
  if (lVar10 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,local_90,local_88,plVar16);
  return (code *)0x0;
}
